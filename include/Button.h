#ifndef BUTTON_H
#define BUTTON_H
#include "Sprite.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include "Label.h"


namespace game {	
	class Button : public Sprite{
	private:
		std::string text;
		SDL_Texture* texture;
		SDL_Texture* Icon;
		bool isDown = false;
		Label* lbl;
	public:
		static Button* getInstance(int x, int y, int w, int h, std::string txt , Label* label);
		void mouseDown(const SDL_Event& eve);
		void mouseUp(const SDL_Event& eve);
		void draw() const;
		void tick();
		virtual void perform(Button* source) {}
		~Button();
	protected:
		Button(int x, int y, int w, int h, std::string txt, Label* label);
	};
}
#endif