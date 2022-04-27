#include "Sprite.h"  

namespace game {	
    Sprite::Sprite(int x, int y, int w, int h) : rect{x,y,w,h} {
	
    }

    const SDL_Rect& Sprite::getRect() const {
		return rect;
	}

	void Sprite::setRectX(int newX) {
		rect.x = newX;
	}
		
    void Sprite::setRectY(int newY) {
		rect.y = newY;
	}
		
    void Sprite::setRectXPlusEtt() {
		rect.x++;
	}
		
    void Sprite::setRectXMinusEtt() {
		rect.x--;
	}
		
    void Sprite::setRectYPlusEtt() {
		rect.y++;
	}

    void Sprite::setRectYMinusEtt() {
        rect.y--;
    }
	
    Sprite::~Sprite() {
        
    }

}