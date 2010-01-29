// Shape.cpp
// Class for creating Shapes in a wizSDLapp
#include "Shape.h"

std::vector<Shape*>* Shape::shapes;
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//::::::::::::::::::::::::::Shape CLASS METHODS::::::::::::::::::::::://
//colored shape constructor
Shape::Shape(int x=0, int y=0, int w=25, int h=25,  int r=0, int g=0, int b=200) : textures(NULL) {
	drawRect.w = w;
	drawRect.h = h;
	drawRect.x = x;
	drawRect.y=y;
	red = r;
	green = g;
	blue = b;
}
//textured shape constructor
Shape::Shape(int x, int y, int w, int h, Textures* txtrs, int txtrNum) {
	drawRect.w = w;
	drawRect.h = h;
	drawRect.x = x;
	drawRect.y=y;
	textures = txtrs;
	textureNum = txtrNum;
}

void Shape::drawAll(SDL_Surface** drawHere) {
	//run draw method for all existing shapes
	for(int n=0; n<(int)Shape::shapes->size(); n++) {
		Shape::shapes->at(n)->draw(drawHere);
	}
}

void Shape::draw(SDL_Surface** drawHere) {
	//textured Shape
	if(textures) {
		if(textures->isAnimated()) {
			//draw
			SDL_BlitSurface(textures->getTextures(),textures->getTexture(),*drawHere,&drawRect);
			//handle texture animation only when it needs to change
			if(SDL_GetTicks() % textures->getAnimationSpeed() == 0) {
				textures->handleAnimation();
			}
		} else {
			//draw non-animated texture
			SDL_BlitSurface(textures->getTextures(),textures->chooseTexture(textureNum),*drawHere,&drawRect);
		}
		
	}
	//colored Shape
	else if(!textures) {
		//static texture
		//draw
		SDL_FillRect((*drawHere),&drawRect,SDL_MapRGB((*drawHere)->format,red,green,blue));
		
	}
}

void Shape::addNew(Shape* newShape) {
	//if there is no shapes container, create one
	if(!Shape::shapes)
		Shape::shapes = new std::vector<Shape*>();
	//Add the new shape to the container
	Shape::shapes->push_back(newShape);
	fprintf(stdout, "Shape Added!\n");
}

void Shape::cleanupShapes() { 
	//memory cleanup of all shapes and shapes container  - call when done with shapes
	fprintf(stdout,"cleanupShapes: Empty shapes container\n");
	int numofshapes = Shape::shapes->size();
	int n = 0;
	while(n<numofshapes) {
			fprintf(stdout,"        cleanupShapes: Delete shape %d\n",n);
			delete Shape::shapes->at(n);
			n++;
	}
	fprintf(stdout,"cleanupShapes: Delete shapes container\n");
	delete Shape::shapes;
} 

void Shape::addToX(int n) { 
	drawRect.x += n; 
}

void Shape::addToY(int n) { 
	drawRect.y += n; 
}
//:::::::::::::::::::::::Shape CLASS METHODS::::::::::::::::::::::::::://
//:::::::::END::::::::::::::::::::::::::::::::::::::::::::::::::::::::END:::::::://
