// Move.h
// SDL_OpenGL_app Class for binding movement controls to a Shape object
#ifndef Move_H
#define Move_H
  
 #include "SDL.h"
 #include "Shape.h"
 
class Move {
		protected:
			const int MOVE_SPEED;
			Shape* object;
			Shape* object2;
			//disable/enable move
			bool offMove;
			Uint8* keystate;
		public:
			Move();
			void bindObject(Shape* obj);
			void bindObject2(Shape* obj);
			virtual void handle() = 0;
			void disable();
			void enable();
};

class KeyMove : public Move {
		private:
		public:
			void handle();
};

class MouseMove : public Move {
		private:
		public:
			void handle();
};

class JoyMove : public Move {
		private:
			bool up, down, left, right;
		public:
			JoyMove();
			void handle();
			void handle(SDL_Event event, SDL_Joystick* joystick);
};

class WizMove : public Move {
	private:
		int up, down, left, right, menu, select, a, b, x, y, L, R, volUp, volDown;
	public:
		WizMove();
		void handle();
		void handle(SDL_Joystick* joystick);
};

#endif
