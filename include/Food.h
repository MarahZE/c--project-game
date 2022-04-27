#ifndef FOOD_H
#define FOOD_H
#include "Sprite.h"
#include <SDL.h>
#include "Label.h"
#include "Player.h"
#include <string>

namespace game {	
	class Food : public Sprite {
	private:
		SDL_Surface* foodSurf;
		SDL_Texture* foodTexture;
		int counter = 0;
		Label* lbl;
		Player* player;
		int point;
	public:
		static Food* getInstance(int x, int y, int w, int h, Label* label, Player* pl, std::string nameImage, int addPoint);
		void draw() const;
		bool detectCollidaction();
		void addPoints();
		void tick();
		~Food();
	protected:
		Food(int x, int y, int w, int h, Label* label, Player* pl, std::string nameImage, int addPoint);
	};
	extern std::string imagePath;
}
#endif