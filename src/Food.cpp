#include "Food.h"
#include "System.h"  
#include "Session.h"
#include <string>
#include <iostream>



	
namespace game {
    Food::Food(int x , int y, int w, int h, Label* label, Player* pl, std::string nameImage, int addPoint) : Sprite(x,y,w,h) , lbl(label), player(pl) {
	    foodSurf = SDL_LoadBMP( (imagePath + nameImage).c_str() );
        Uint32 white = SDL_MapRGB(foodSurf->format,255,255,255);
	    SDL_SetColorKey(foodSurf, true, white);
        foodTexture = SDL_CreateTextureFromSurface(sys.get_ren(), foodSurf);
        SDL_FreeSurface(foodSurf);
        point = addPoint;
    }

    Food* Food::getInstance(int x, int y, int w, int h, Label* label, Player* pl, std::string nameImage, int addPoint) {
        return new Food(x,y,w,h,label,pl,nameImage,addPoint);
    }

    void Food::draw() const {
        SDL_RenderCopy(sys.get_ren(), foodTexture, NULL, &getRect());
    }

    bool Food::detectCollidaction() {
        if (getRect().y == player->getRect().y && (getRect().x - 60 <= player->getRect().x &&  player->getRect().x <= getRect().x)) {
            return true;
        } else {
            return false;
        }
    }

    void Food::tick() {
        counter++; 
        if (counter % 10 == 0)
            setRectY(getRect().y + 3);
        if (getRect().y > 580) {
            setRectY(1);
        } else if (detectCollidaction()) {
            setRectY(1);
           // v += point;
           // lbl->setText(std::to_string(v));
           addPoints();
        }
    }

    void Food::addPoints() {
        std::string value = lbl->getText();
        int v = stoi(value);
        v += point;
        lbl->setText(std::to_string(v));
    }


    Food::~Food()
    {
	    SDL_DestroyTexture(foodTexture);
    }
}