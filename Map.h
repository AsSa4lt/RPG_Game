//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Game.h"


class Map {
public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();
private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture * water;

    int map[20][25];
};


#endif //GAME_MAP_H
