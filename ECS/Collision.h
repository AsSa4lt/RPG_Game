//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H
#include "SDL.h"

class Collision{
public:
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
};


#endif //GAME_COLLISION_H
