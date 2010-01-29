// Textures.cpp
// Class for loading textures to be used in a WizSDLapp
#include "Textures.h"
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
//::::::::::::::::::::::Textures CLASS METHODS::::::::::::::::::::::://
Textures::Textures(const char* file, int w, int h, int numPerRow) : animated(false), row(0), animationSpeed(100) {
	textures[0] = SDL_LoadBMP(file);
	if(textures[0] == NULL) {
		// Texture Required, exit here.
		printf("Texture Creation failed: %s\n", SDL_GetError());
		exit(1);
	}
	//set transparent color key
	SDL_SetColorKey(textures[0],SDL_SRCCOLORKEY,SDL_MapRGB(textures[0]->format, 255, 0, 255));
	width = grabRect.w = w;
	height = grabRect.h = h;
	perRow = numPerRow;
	totalRows = 1;
	fprintf(stdout,"Texture Added\n");
}
Textures::Textures(const char* files[], int w, int h, int numPerRow) : animated(true), row(0), animationSpeed(150) {
	for(int x=0; files[x] != NULL; x++) {
		//set files for textures
		textures[x] = SDL_LoadBMP(files[x]);
		//check for texture load error
		if(textures[x] == NULL) {
			// Texture Required, exit here.
			printf("Texture Creation failed: %s\n", SDL_GetError());
			exit(1);
		}
		//set transparent color key
		SDL_SetColorKey(textures[x],SDL_SRCCOLORKEY,SDL_MapRGB(textures[x]->format, 255, 0, 255));
		totalRows = x;
		fprintf(stdout,"Texture File Added\n");
	}
	width = grabRect.w = w;
	height = grabRect.h = h;
	perRow = numPerRow;
}

void Textures::changeFile(const char* file) {
	//load a new bmp textures file
	textures[0] = SDL_LoadBMP(file);
	if(textures[0] == NULL) {
		// Texture not found. Texture Required, exit here.
		printf("Texture::changeFile failed: %s\n", SDL_GetError());
		exit(1);
	}
}

SDL_Rect* Textures::chooseTexture(int num) {
	//set y coordinates equal to the row the texture should be on
	grabRect.y = 0;
	if(num>perRow) {
		while(num>perRow) {
			//increment y coord to next row
			grabRect.y += height;
			num -= perRow;
		}
	}
	//set x coord
	grabRect.x = ( (width * num) - width );
	
	//return the selected texture
	return &grabRect;
}

SDL_Surface* Textures::getTextures() { return textures[row]; }
SDL_Rect* Textures::getTexture() { return &grabRect; }

int Textures::getPerRow() { return perRow; }

void Textures::animateOn() {
	animated = true;
	//initialize grabRect to first frame
	grabRect.x = grabRect.y =0;
	animationFrame = 1;
}
void Textures::animateOff() { animated = false; }
bool Textures::isAnimated() { return animated; }
void Textures::setAnimationSpeed(int newSpeed) { animationSpeed = newSpeed; }
void Textures::incAnimationSpeed() {
	if(animationSpeed != 10)
		animationSpeed -= 2;
}
void Textures::decAnimationSpeed() {
	if(animationSpeed != 300)
		animationSpeed += 2;
}
int Textures::getAnimationSpeed() { return animationSpeed; }

void Textures::handleAnimation() {
	
	//slow down animation so it runs with program
	if(SDL_GetTicks() % animationSpeed == 0) {
		animationFrame++;
		chooseTexture(animationFrame);
		fprintf(stdout,"Next Frame : %d\n",animationFrame);
	}
	
	//when animation reaches end of row 
	if( animationFrame > perRow ) {
		//if multi-file animation, handle
		if(totalRows > 1) {
			fprintf(stdout,"Next Row\n");
			//next row
			if(row<totalRows) {
				fprintf(stdout,"Next Row%d\n", row+1);
				row++;
			//loop back to first row
			} else if(row==totalRows) {
				fprintf(stdout,"Loop Back to First Row\n");
				row=0;
			}
		}
		//in either case select the first texture in file
		fprintf(stdout,"animationFrame=1\n");
		fprintf(stdout,"perRow=%d\n",perRow);
		animationFrame = 1;
		chooseTexture(1);
	}
}
//::::::::::::::::::::::Textures CLASS METHODS:::::::::::::::::::::::://
//:::::::::END::::::::::::::::::::::::::::::::::::::::::::::::::::::::END:::::::://

