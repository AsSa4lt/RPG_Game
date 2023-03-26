//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_SPRITECOMPONENT_H
#define GAME_SPRITECOMPONENT_H
#include "ECS.h"
#include "Components.h"
#include "../Game.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent: public Component{
private:
    TransformComponent *tranform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    bool animated = false;
    int frames = 0;
    int speed = 100;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTex(path);
    }

    SpriteComponent(const char* path, int nFrames, int mSpeed){
        animated = true;
        frames = nFrames;
        speed = mSpeed;
        setTex(path);
    }




    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }

    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }

    void init() override{
        tranform = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = tranform->width;
        srcRect.h = tranform->heigth;

    }
    void update() override{
        if(animated){
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks()/speed) % frames);
        }


        destRect.x = static_cast<int>(tranform->position.x);
        destRect.y = static_cast<int>(tranform->position.y);
        destRect.w = tranform->width*tranform->scale;
        destRect.h = tranform->heigth*tranform->scale;
    }
    void draw() override{
        TextureManager::Draw(texture, srcRect, destRect);
    }
};

#endif //GAME_SPRITECOMPONENT_H
