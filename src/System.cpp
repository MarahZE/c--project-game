#include "System.h"
#include <SDL.h> 
#include <SDL_image.h> 
#include <stdexcept>

namespace game {	
    System::System()
    
    { 
        int code = SDL_Init(SDL_INIT_EVERYTHING);
        if (code == -1)
            throw std::runtime_error(std::string("Initfel:") + SDL_GetError());
        win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600 , 0);
        if (win == nullptr)
            throw std::runtime_error(std::string("Can't create window: ") + SDL_GetError());
        ren = SDL_CreateRenderer(win, -1, 0);
        if (ren == nullptr)
            throw std::runtime_error(std::string("Can't create renderer: ") + SDL_GetError());

        int code1 = TTF_Init();
        if (code1 == -1)
            throw std::runtime_error(std::string("TTF_Initfel:") + SDL_GetError());
        fontPath = "../../resources/fonts/";
        font = TTF_OpenFont((fontPath + "arial.ttf").c_str(), 24);

        imagePath = "../../resources/images/";
        imageSurf = IMG_Load((imagePath + "background.jpg").c_str());

        texture = SDL_CreateTextureFromSurface(ren,imageSurf);
        SDL_FreeSurface(imageSurf);

        int code3 = Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
        if (code3 == -1)
            throw std::runtime_error(std::string("Initfel:") + SDL_GetError());

        soundPath = "../../resources/sounds/";
	    musik = Mix_LoadWAV((soundPath + "bgMusic.wav").c_str());
        int channel = Mix_PlayChannel(-1, musik, -1);
	    Mix_Volume(channel, 10);
    }
	
    System::~System()
    {
       // Mix_FreeChunk(musik);
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::get_ren() const {
        return ren;
    }

    TTF_Font* System::get_font() const {
        return font;
    }

    SDL_Texture* System::get_tximage() const {
        return texture;
    }

    System sys;

}