//
// Created by Rostyslav on 26.03.2023.
//

#ifndef GAME_TILECOMPONENT_H
#define GAME_TILECOMPONENT_H
#include "ECS.h"
#include "SDL.h"
#include "../TextureManager.h"


class TileComponent : public Component{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    TileComponent() = default;
    TileComponent(int srcX, int srcY, int xpos, int ypos, const char* path){
        texture = TextureManager::LoadTexture(path);
        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = 32;

        destRect.x = xpos;
        destRect.y = ypos;
        destRect.w = destRect.h = 64;
    }

    ~TileComponent(){
        SDL_DestroyTexture(texture);
    }

    void draw() override{
        TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
    }

};


#endif //GAME_TILECOMPONENT_H
