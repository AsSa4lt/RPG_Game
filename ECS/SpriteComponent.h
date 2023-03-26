//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_SPRITECOMPONENT_H
#define GAME_SPRITECOMPONENT_H
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "map"
#include "Animation.h"

class SpriteComponent: public Component{
private:
    TransformComponent *tranform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    bool animated = false;
    int frames = 0;
    int speed = 100;
public:
    int animIndex = 0;
    std::map<const char*, Animation> animations;
    SDL_RendererFlip  spriteFlip = SDL_FLIP_NONE;

    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTex(path);
    }

    SpriteComponent(const char* path, bool isAnimated){
        animated = isAnimated;

        Animation idle = Animation(0, 3, 100);
        Animation walk = Animation(1, 8, 100);

        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);

        Play("Idle");
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
        srcRect.y = animIndex*tranform->heigth;

        destRect.x = static_cast<int>(tranform->position.x);
        destRect.y = static_cast<int>(tranform->position.y);
        destRect.w = tranform->width*tranform->scale;
        destRect.h = tranform->heigth*tranform->scale;
    }
    void draw() override{
        TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
    }

    void Play(const char* animName){
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }
};

#endif //GAME_SPRITECOMPONENT_H
