#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace game {	
	class Label : public Sprite {
	private:
		std::string text;
		SDL_Texture* texture;
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	public:
		static Label* getInstance(int x, int y, int w, int h, std::string txt);
		void draw() const;
		void tick();
		std::string getText() const;
		void setText(std::string newText);
		~Label();

	};
	
}
#endif