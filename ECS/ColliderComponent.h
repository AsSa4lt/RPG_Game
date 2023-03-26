 //
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_COLLIDERCOMPONENT_H
#define GAME_COLLIDERCOMPONENT_H
#include "SDl.h"
#include "Components.h"


class ColliderComponent : public Component{
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent* tranform;

    ColliderComponent(std::string t){
        tag = t;
    }

    void init() override{
        if(!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>();
        }
        tranform = &entity->getComponent<TransformComponent>();

        Game::colliders.push_back(this);
    }

    void update() override{
        collider.x = static_cast<int>(tranform->position.x);
        collider.y = static_cast<int>(tranform->position.y);
        collider.w = (int)tranform->width*tranform->scale;
        collider.h = tranform->heigth * tranform->scale;
    }
};


#endif //GAME_COLLIDERCOMPONENT_H
