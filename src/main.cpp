#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"


int main() {

    const int FPS = 30;
    const int FRAME_DELAY = 1000 / FPS;

    Uint32 frameStart, frameTime; 
    
    TheGame::Instance();

    TheGame::Instance()->Init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);

    while(TheGame::Instance()->running()){

        frameStart = SDL_GetTicks();

        TheGame::Instance()->update();
        TheGame::Instance()->render();
        TheGame::Instance()->handleEvents();

        //how much did the above operations took (cpu clock speeds)

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < FRAME_DELAY){
            SDL_Delay((int) (FRAME_DELAY - frameTime));
        }
    }
    TheGame::Instance()->clean();

    return 0;
}
