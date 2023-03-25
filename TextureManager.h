//
// Created by Rostyslav on 24.03.2023.
//

#ifndef GAME_TEXTUREMANAGER_H
#define GAME_TEXTUREMANAGER_H
#include "Game.h"


class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};


#endif //GAME_TEXTUREMANAGER_H
