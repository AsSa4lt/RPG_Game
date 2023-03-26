//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_TRANSFORMCOMPONENT_H
#define GAME_TRANSFORMCOMPONENT_H


#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component{
public:
    Vector2D position;
    Vector2D velocity;

    int speed = 3;

    int heigth = 32;
    int width = 32;
    int scale = 1;

    TransformComponent(){
        position.Zero();
    }

    TransformComponent(int sc){
        position.Zero();
        scale = sc;
    }

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int h, int w, int sc){
        position.x = x;
        position.y = y;
        heigth = h;
        width = w;
        scale = sc;
    }

    void init() override{
        velocity.Zero();
    }

    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};


#endif //GAME_TRANSFORMCOMPONENT_H
