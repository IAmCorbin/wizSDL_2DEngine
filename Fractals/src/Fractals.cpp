// Fractals.cpp
// WizSDLapp development
#include "Fractals.h"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//::::::::::::::::::::Fractals CLASS METHODS:::::::::::::::::::::://
Fractals::Fractals() {
	
	//array of all files needed for this fractal, pass NULL as last value to indicate end of array
	const char* backgroundFiles[14] = {
						"data/textures/julia_a61_1.bmp",
						"data/textures/julia_a61_2.bmp",
						"data/textures/julia_a61_3.bmp",
						"data/textures/julia_a61_4.bmp",
						"data/textures/julia_a61_5.bmp",
						"data/textures/julia_a61_6.bmp",
						"data/textures/julia_a61_7.bmp",
						"data/textures/julia_a61_8.bmp",
						"data/textures/julia_a61_9.bmp",
						"data/textures/julia_a61_10.bmp",
						"data/textures/julia_a61_11.bmp",
						"data/textures/julia_a61_12.bmp",
						"data/textures/julia_a61_13.bmp",
						NULL};
	//load background fractal files
	background = new Textures(backgroundFiles,320,240,5);
	//create shape and apply background texture
	Shape::addNew(new Shape(0,0,320,240,background,1));

	//walking Owl
	owlWalk = new Textures((char*)"data/textures/owlWalk_a21x30.bmp",21,30,3);
	owlWalk->setAnimationSpeed(100);
	owlWalk->animateOn();
	Shape::addNew(new Shape(210,210,21,30,owlWalk,1));
	controlOwl.bindObject(Shape::shapes->at(1));
						
	//flying Owl
	owlFly = new Textures((char*)"data/textures/owlFly_a32x64.bmp",32,64,4);						
	owlFly->setAnimationSpeed(100);
	owlFly->animateOn();
	Shape::addNew(new Shape(100,50,64,32,owlFly,1));
	controlOwl.bindObject2(Shape::shapes->at(2));
}
Fractals::~Fractals() {
	Shape::cleanupShapes();
}

void Fractals::drawFrame() {
	clearScreen();
	Shape::drawAll(&wizScreen);
}

void Fractals::handleEvents() {
}

void Fractals::handleUserInput() {	
	controlOwl.handle(wizJoy);
}
//::::::::::::::::::::Fractals CLASS METHODS:::::::::::::::::::::://
//:::::::::END::::::::::::::::::::::::::::::::::::::::::::::::::::::::END:::::::://
int main(int argc, char* argv[]) {
	
	Fractals Game;
	Game.run();
	
	return 0;
}
