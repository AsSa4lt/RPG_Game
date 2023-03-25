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
    TransformComponent *tranform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }

    void init() override{
        tranform = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = tranform->width;
        srcRect.h = tranform->heigth;
        destRect.w = tranform->width*tranform->scale;
        destRect.h = tranform->heigth*tranform->scale;
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
