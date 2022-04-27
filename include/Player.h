#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace game {	
	class Player : public Sprite{
	private:
		SDL_Surface* imageSurf;
		SDL_Texture* texture;
		bool drag = false;
	public:
		static Player* getInstance(int x, int y, int w, int h);
		void draw() const;
		void tick();
		void keyDown(const SDL_Event& eve);
		SDL_Surface* getImageSurf() const;
		~Player();
	protected:
		Player(int x, int y, int w, int h);
	};
	extern std::string imagePath;
}
#endif