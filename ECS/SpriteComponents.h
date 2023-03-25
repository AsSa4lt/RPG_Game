//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_SPRITECOMPONENTS_H
#define GAME_SPRITECOMPONENTS_H
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent: public Component{
private:
    TranformComponent *tranform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    void init() override{
        tranform = &entity->getComponent<TranformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }
    void update() override{
        destRect.x = (int)tranform->position.x;
        destRect.y = (int)tranform->position.y;
    }
    void draw() override{
        TextureManager::Draw(texture, srcRect, destRect);
    }
};

#endif //GAME_SPRITECOMPONENTS_H
