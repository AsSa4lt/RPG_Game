#include <iostream>

#include "Game.h"
Game *game = nullptr;
int main() {
    game = new Game();
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    uint32_t frameStart;
    int frameTime;

    game->init("Game", 800, 640, false);
    while (game->running()){
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }
    game->clean();
    return 0;
}
