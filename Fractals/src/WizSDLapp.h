// WizSDLapp.h
// Base class for creating an SDL application for use on the GP2X Wiz Handheld linux based gaming device
#ifndef H_WizSDLapp
#define H_WizSDLapp

#include "SDL.h"
#include "Shape.h"
#include "Move.h"
//for executing the GP2X Wiz Menu
#include <unistd.h>

class WizSDLapp {
	protected:
		//DATA
		SDL_Surface* wizScreen;
		const int WIDTH;
		const int HEIGHT;
		SDL_Event event;
		SDL_Joystick* wizJoy;
		SDL_Rect rect;
	
		//gameover trigger
		bool gameover;
	public:
		//METHODS
		//constructor
		WizSDLapp();
		//destructor
		~WizSDLapp();
		//initialize SDL
		void initSDL();
		//run the program
		void run();
		//clear the screen to black
		void clearScreen();
		//draw a frame
		virtual void drawFrame() =0;
		//handle events
		virtual void handleEvents() = 0;
		//handle user input
		virtual void handleUserInput() = 0;
		//return gameover status
		bool isGameover();
		void setGameover(bool state);
};

#endif
