#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>

namespace game {	
	class System  
	{
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
		SDL_Surface* imageSurf;
		SDL_Texture* texture;
		Mix_Chunk* musik;
	public:
		System();
		~System();
		SDL_Renderer* get_ren() const;
		TTF_Font* get_font() const;
		SDL_Texture* get_tximage() const;

	};
	extern System sys;
	extern std::string imagePath;
	extern std::string fontPath;
	extern std::string soundPath;

}
#endif