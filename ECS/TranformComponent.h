//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_TRANFORMCOMPONENT_H
#define GAME_TRANFORMCOMPONENT_H


#include "Components.h"
#include "Vector2D.h"

class TranformComponent : public Component{
public:
    Vector2D position;
    Vector2D velocity;

    int speed = 3;

    TranformComponent(){
        position.x  = 0.0f;
        position.y = 0.0f;
    }

    TranformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
    void init() override{
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};


#endif //GAME_TRANFORMCOMPONENT_H
