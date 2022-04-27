#include "Button.h" 
#include <iostream>
#include <string> 
#include <SDL_ttf.h>
#include "System.h"
#include <SDL_image.h>
#include "Label.h"
#include "Session.h"
	
using namespace std;
namespace game {
    Button::Button(int x, int y, int w, int h, string txt, Label* label) : Sprite(x,y,w,h), text(txt) , lbl(label) {
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(),txt.c_str(), {0,0,0}); 
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);

        std::string imagePath = "../../resources/images/";
        Icon = IMG_LoadTexture(sys.get_ren(), (imagePath + "whiteIcon.png").c_str());

    }

    Button* Button::getInstance(int x, int y, int w, int h, string txt, Label* label) {
        return new Button(x,y,w,h,txt,label);
    }

    void Button::draw() const {
        SDL_RenderCopy(sys.get_ren(), Icon, NULL, &getRect());
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    }

    void Button::tick() {

    }

    void Button::mouseDown(const SDL_Event& eve) {
        SDL_Point p = { eve.button.x, eve.button.y};
        if (SDL_PointInRect(&p, &getRect()))
            isDown = true;
    }

    void Button::mouseUp(const SDL_Event& eve) {
        SDL_Point p = { eve.button.x, eve.button.y};
        if (SDL_PointInRect(&p, &getRect())) {
            lbl->setText("0");
        }
        isDown = false;
    }
	
    Button::~Button()
    {
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(Icon);
    }
}