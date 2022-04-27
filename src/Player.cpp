#include "Player.h" 
#include <SDL_image.h>
#include "System.h" 
#include <string>
	
namespace game {

    Player::Player(int x, int y, int w, int h) : Sprite(x,y,w,h) {
        imagePath = "../../resources/images/";
        imageSurf = SDL_LoadBMP((imagePath + "gubbe.bmp").c_str());
        Uint32 white = SDL_MapRGB(imageSurf->format,255,255,255);
	    SDL_SetColorKey(imageSurf, true, white);
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), imageSurf);
        SDL_FreeSurface(imageSurf);
    }

    SDL_Surface* Player::getImageSurf() const {
        return imageSurf;
    }

    Player* Player::getInstance(int x, int y, int w, int h) {
        return new Player(x,y,w,h);
    }

    void Player::draw() const {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    }

    void Player::tick() {
        
    }

    void Player::keyDown(const SDL_Event& eve) {
        switch (eve.key.keysym.sym)
        {
        case SDLK_RIGHT:  
            setRectXPlusEtt();
            if (getRect().x > 700)
                setRectX(0);
        break;
		case SDLK_LEFT: 
            setRectXMinusEtt(); 
            if (getRect().x < 0)
                setRectX(700);
        break;
        }
    }


    Player::~Player()
    {
        SDL_DestroyTexture(texture);
    }

}