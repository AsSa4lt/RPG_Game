//
// Created by Rostyslav on 24.03.2023.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include "SDL.h"
#include "SDL_image.h"


class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void render();
    void clean();
    void handleEvents();

    bool running();

    static SDL_Renderer *renderer;
private:
    int cnt = 0;
    bool isRunning;
    SDL_Window * window;
};


#endif //GAME_GAME_H
