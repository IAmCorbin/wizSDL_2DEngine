// Textures.h
// Class for loading textures to be used in a WizSDLapp
#ifndef Textures_H
#define Textures_H

#include "SDL.h"

class Textures {
	private:
		//DATA
		//size of a single texture
		int width, height;
		//number of textures per row
		int perRow;
		//texture surface
		//array for multi-file animations (used because of SDL_loadBMP width limit of 1600px)
		SDL_Surface* textures[25];
		//rectangle for selecting specific texture in textures surface
		SDL_Rect grabRect;
	
		//animated texture switch
		bool animated;
		//to keep track of the current animation frame
		int animationFrame;
		//how fast is the animation played
		int animationSpeed;
	
		//used to navigate files
		int row, totalRows;
	public:
		//METHODS
		//constructor - single file texture
		Textures(const char* file, int w, int h, int numPerRow);
		//constructor - multi-file texture animation
		Textures( const char* files[], int w, int h, int numPerRow);
		//set up the grabRect to select a specific texture
		SDL_Rect* chooseTexture(int num);
		//return the textures
		SDL_Surface* getTextures();
		//return the currently selected texture
		SDL_Rect* getTexture();
		//return the number of textures per row set in texture constructor
		int getPerRow();
		void animateOn();
		void animateOff();
		bool isAnimated();
		//modify animation speed
		void setAnimationSpeed(int newSpeed);
		void incAnimationSpeed();
		void decAnimationSpeed();
		int getAnimationSpeed();
		void handleAnimation();
		
		//set files for multi-row animated textures
		//void setFiles(const char* newFiles[]);
		//change the texture file
		void changeFile(const char* file);
};

#endif
