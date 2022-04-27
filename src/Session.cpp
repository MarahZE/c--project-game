#include "Session.h" 
#include "System.h" 
#include "Food.h"
#include <SDL.h>

#define FPS 60

namespace game {
    void Session::add(Sprite* c) {
        tempAdded.push_back(c);
    }

    void Session::run() {
        bool quit = false;

        Uint32 tickInterval = 1000 / FPS;
        while (!quit){
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event eve;
            while(SDL_PollEvent(&eve)) {
                switch(eve.type) {
                    case SDL_QUIT: quit = true; break;
                    case SDL_MOUSEBUTTONDOWN:
                        for(Sprite* c: sprits)
                            c->mouseDown(eve);
                        break;
                    case SDL_MOUSEBUTTONUP:
                        for(Sprite* c: sprits)
                            c->mouseUp(eve);
                        break;
                    case SDL_KEYDOWN:
                        for(Sprite* c: sprits)
                            c->keyDown(eve);
                        break;
                    case SDL_KEYUP:
                        for(Sprite* c: sprits)
                            c->keyUp(eve);
                        break;
                } // switch
            } //inre loop

            //tick function måste göras....
            for (Sprite* c : sprits)
			    c->tick();

            for (Sprite* c : tempAdded)
                sprits.push_back(c);
            tempAdded.clear();


            SDL_RenderClear(sys.get_ren());
            SDL_RenderCopy(sys.get_ren(), sys.get_tximage(), NULL, NULL);
            for(Sprite* c: sprits)
                c->draw();
            SDL_RenderPresent(sys.get_ren());

            int delay = nextTick - SDL_GetTicks();
            if (delay > 0)
                SDL_Delay(delay);
        } // yttre loop
        
    }

    Session::~Session()
    {  
	
    }

    Session ses;

}