// WizSDLapp.cpp
// Base class for creating an SDL application for use on the GP2X Wiz Handheld linux based gaming device
#include "WizSDLapp.h"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//::::::::::::::::::::WizSDLapp CLASS METHODS::::::::::::::::::::://
WizSDLapp::WizSDLapp() : WIDTH(320), HEIGHT(240), gameover(false) {
	initSDL();
	
	//connect to Wiz Joystick
	wizJoy=SDL_JoystickOpen(0);
	//enable joystick events
	SDL_JoystickEventState(SDL_ENABLE);
}

WizSDLapp::~WizSDLapp() {
	//close the joystick
	SDL_JoystickClose(wizJoy);
	//normal termination
	fprintf(stdout,"Terminating normally.\n");
	
	//Return to Wiz menu
	if(chdir("/usr/gp2x"));
	execl("/usr/gp2x/gp2xmenu", "/usr/gp2x/gp2xmenu", NULL);
}

void WizSDLapp::initSDL() {
	//initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)==-1) {
		//error initializing SDL
		fprintf(stderr,"Could not initialize SDL!\n");
		//end the program
		exit(1);
	} else {
		//SDL initialized
		fprintf(stdout,"SDL initialized properly!\n");
		//set up to uninitialize SDL at exit
		atexit(SDL_Quit);
	}

	//create windowed environment
	wizScreen = SDL_SetVideoMode(WIDTH,HEIGHT,0,SDL_ANYFORMAT);
	//error check
	if (wizScreen == NULL) {
		//report error
		fprintf(stderr,"Could not set up display surface!\n");
		//exit the program
		exit(1);
	}
}

void WizSDLapp::run() {
	//repeat until gameover triggered
	while(!this->gameover) {
		drawFrame();
		//wait for an event
		if(SDL_PollEvent(&event)==0) {
			//no event
			
			//handle user input
			handleUserInput();
			
			//set gameover on Vol+ & Vol- press
			if( SDL_JoystickGetButton(wizJoy,16) && SDL_JoystickGetButton(wizJoy,17) )
				setGameover(true);
		
		} else {
			//event occurred, check for quit
			if(event.type==SDL_QUIT) {
				gameover = true;
				break;
			}
			//handle events
			handleEvents();
		}
		//update the screen
		SDL_UpdateRect(wizScreen,0,0,0,0);
	}
}

//clear screen to black
void WizSDLapp::clearScreen() { 
	SDL_FillRect(wizScreen, NULL, SDL_MapRGB(wizScreen->format,0,0,0));
}

bool WizSDLapp::isGameover() { return gameover; }
void WizSDLapp::setGameover(bool state) { gameover = state; }
//::::::::::::::::::::WizSDLapp CLASS METHODS:::::::::::::::::::::://
//:::::::::END::::::::::::::::::::::::::::::::::::::::::::::::::::::::END:::::::://
