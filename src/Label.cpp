#include "Label.h"
#include "System.h"
#include <SDL_ttf.h> 
#include <iostream>
#include <string>

using namespace std;
	
namespace game {
    Label* Label::getInstance(int x, int y, int w, int h, std::string txt) {
        return new Label(x,y,w,h,txt);
    }

    Label::Label(int x, int y, int w, int h, string txt) : Sprite(x,y,w,h), text(txt){
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {0,0,0});
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
    }

    void Label::draw() const{
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    }

    void Label::tick() {
        
    }

    string Label::getText() const {
        return text;
    }

	void Label::setText(string newText) {
        text = newText;
        SDL_DestroyTexture(texture);
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {0,0,0});
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
       // cout << "hello";
    }
	
    Label::~Label() {
        SDL_DestroyTexture(texture);
    }

}