// Move.cpp
// SDL_OpenGL_app Class for binding movement controls to a Shape object
#include "Move.h"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//:::::::::::::Move CLASS METHODS::::::::::::::::::::::::::::::::::::://
Move::Move() : offMove(false), MOVE_SPEED(1) { }

void Move::bindObject(Shape* obj) {
	object = obj;
}
void Move::bindObject2(Shape* obj) {
	object2 = obj;
}

void Move::disable() {
	offMove = true;
}

void Move::enable() {
	offMove = false;
}
//:::::::::::::Move CLASS METHODS:::::::::::::::::::::::::::::::::::::://
//:::::END:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END::::::://


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//:::::::::::::KeyMove CLASS METHODS::::::::::::::::::::::::::::::::::::://
void KeyMove::handle() { 
	
	keystate = SDL_GetKeyState(NULL);
	if(keystate[SDLK_w]) {
		object->addToY(-MOVE_SPEED);
	}
	if(keystate[SDLK_a]) {
		object->addToX(-MOVE_SPEED);
	}
	if(keystate[SDLK_s]) {
		object->addToY(MOVE_SPEED);
	}
	if(keystate[SDLK_d]) {
		object->addToX(MOVE_SPEED);
	}
	
	if(keystate[SDLK_LEFT]) {
		object2->addToX(-MOVE_SPEED);
	}
	if(keystate[SDLK_RIGHT]) {
		object2->addToX(MOVE_SPEED);
	}
	if(keystate[SDLK_DOWN]) {
		object2->addToY(MOVE_SPEED);
	}
	if(keystate[SDLK_UP]) {
		object2->addToY(-MOVE_SPEED);
	}
	/*
	if(keystate[SDLK_DOWN]) {
		object->decAnimationSpeed();
		fprintf(stdout,"Animation Speed: %d\n",object->getAnimationSpeed());
	}
	if(keystate[SDLK_UP]) {
		object->incAnimationSpeed();
		fprintf(stdout,"Animation Speed: %d\n",object->getAnimationSpeed());
	}
	if(keystate[SDLK_LEFT]) {
		object->animateOn();
	}	
	if(keystate[SDLK_RIGHT]) {
		object->animateOff();
	}
	*/
}
//:::::::::::::KeyMove CLASS METHODS:::::::::::::::::::::::::::::::::::::://
//:::::END:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END::::::://



//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//:::::::::::::MouseMove CLASS METHODS::::::::::::::::::::::::::::::::::::://
void MouseMove::handle() { 
		
	
}
//:::::::::::::MouseMove CLASS METHODS:::::::::::::::::::::::::::::::::::::://
//:::::END:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END::::::://



//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//:::::::::::::JoyMove CLASS METHODS::::::::::::::::::::::::::::::::::::://
JoyMove::JoyMove() : up(false), down(false), left(false), right(false) {  }
//for key handling
void JoyMove::handle() { 
	if(up)
		object->addToY(-MOVE_SPEED);
	if(down)
		object->addToY(MOVE_SPEED);
	if(left)
		object->addToX(-MOVE_SPEED);
	if(right)
		object->addToX(MOVE_SPEED);
}
//for event
void JoyMove::handle(SDL_Event event, SDL_Joystick* joystick) { 
	if(event.type==SDL_JOYAXISMOTION) {
		if(event.jaxis.axis==0)
			if(event.jaxis.value>0) {
				left = false;
				right = true;
			}
			else if(event.jaxis.value<0) {
				left = true;
				right = false;
			}
			else if(event.jaxis.value==0) {
				left = false;
				right = false;
			}
		if(event.jaxis.axis==1) 
			if(event.jaxis.value>0) {
				up = true;
				down = false;
			}
			else if(event.jaxis.value<0) {
				up = false;
				down = true;
			}
			else if(event.jaxis.value==0) {
				up = false;
				down = false;
			}
	}
}
//:::::::::::::JoyMove CLASS METHODS:::::::::::::::::::::::::::::::::::::://
//:::::END:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END::::::://

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//:::::::::::::WizMove CLASS METHODS::::::::::::::::::::::::::::::::::::://
WizMove::WizMove() : up(0), left(2), down(4), right(6), menu(8), select(9), L(10), R(11), a(12), b(13), x(14), y(15), volUp(16), volDown(17) { }

void WizMove::handle() { }

void WizMove::handle(SDL_Joystick* joystick) {
	
	if( SDL_JoystickGetButton(joystick,up) ) {
		object->addToY(-MOVE_SPEED);
	}
	if( SDL_JoystickGetButton(joystick,left) ) {
		object->addToX(-MOVE_SPEED);
	}
	if( SDL_JoystickGetButton(joystick,down) ) {
		object->addToY(MOVE_SPEED);
	}
	if( SDL_JoystickGetButton(joystick,right) ) {
		object->addToX(MOVE_SPEED);
	}
	/*
	if( SDL_JoystickGetButton(joystick, menu) ) {
		object->animateOn();
	}
	if( SDL_JoystickGetButton(joystick, select) ) {
		object->animateOff();
	}*/
	if( SDL_JoystickGetButton(joystick,a) ) {
		object2->addToX(-MOVE_SPEED);
	}
	if( SDL_JoystickGetButton(joystick,b) ) {
		object2->addToX(MOVE_SPEED);
	}
	if( SDL_JoystickGetButton(joystick,x) ) {
		object2->addToY(MOVE_SPEED);
	}
	if( SDL_JoystickGetButton(joystick,y) ) {
		object2->addToY(-MOVE_SPEED);
	}
	
}
//:::::::::::::WizMove CLASS METHODS:::::::::::::::::::::::::::::::::::::://
//:::::END::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::END::::::://
