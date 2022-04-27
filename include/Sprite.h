#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace game {	
	class Sprite  
	{
	private:
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	public:
		//SDL_Rect rect;
		virtual ~Sprite();
		virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseUp(const SDL_Event&) {}
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		virtual void draw() const = 0;
		//tick metod..
		virtual void tick() = 0;
		const SDL_Rect& getRect() const;
		void setRectX(int newX);
		void setRectY(int newY);
		void setRectXPlusEtt();
		void setRectXMinusEtt();
		void setRectYPlusEtt();
	    void setRectYMinusEtt();
	
	protected:
		Sprite(int x, int y, int w, int h);
	};


}
#endif