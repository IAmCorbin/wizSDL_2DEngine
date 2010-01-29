// Fractals.h
// WizSDLapp development
#include "WizSDLapp.h"

class Fractals : public WizSDLapp {
	private:
		//SDL Event Structure
		SDL_Event event;
		//Textures
		Textures* background;
		Textures* owlWalk;
		Textures* owlFly;
		//user control
		WizMove controlOwl;
	public:
		//constructor
		Fractals();
		//destructor
		~Fractals();
	
		void drawFrame();
		void handleEvents();
		void handleUserInput();
};
