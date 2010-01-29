// Shape.h
// Class for creating Shapes in a wizSDLapp
#ifndef Shape_H
#define Shape_H
  
#include "Textures.h"
#include "SDL.h"
//for static Shape Container
#include <vector>

class Shape {
	private:
		//DATA
		//colors
		int red, green, blue;
		//texture
		Textures* textures;
		int textureNum;
	
		//SDL Rectangle for drawing shape
		SDL_Rect drawRect;
	public:
		//container to hold all shapes
		static std::vector<Shape*>* shapes;
		//METHODS
		//colored shape constructor
		Shape(int x, int y, int w, int h, int r, int g, int b);
		//textured shape constructor
		Shape(int x, int y, int w, int h, Textures* txtrs, int txtrNum);
		
		//draw all existing shapes
		static void drawAll(SDL_Surface** drawHere);
		//add a new shape
		static void addNew(Shape* newShape);
		//cleanup memory
		static void cleanupShapes();
		//draw this shape
		void draw(SDL_Surface** drawHere);
	
		//manipulate coordinates
		void addToX(int n);
		void addToY(int n);		
};

#endif
