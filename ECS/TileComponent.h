//
// Created by Rostyslav on 26.03.2023.
//

#ifndef GAME_TILECOMPONENT_H
#define GAME_TILECOMPONENT_H
#include "ECS.h"
#include "Components.h"
#include "SDL.h"
#include "../Game.h"
#include "SpriteComponent.h"


class TileComponent : public Component{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    SDL_Rect tileRect;
    int tileID;
    char* path;

    TileComponent() = default;
    TileComponent(int x, int y, int w, int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w  = w;
        tileRect.h = h;
        tileID = id;
        switch (tileID) {
            case 0:
                path = "../Assets/dirt.png";
                break;
            case 1:
                path = "../Assets/grass.png";
                break;
            case 2:
                path = "../Assets/water.png";

                break;
            default:
                break;
        }
    }



    void init() override{
        entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();
        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};


#endif //GAME_TILECOMPONENT_H
