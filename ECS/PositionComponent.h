//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_POSITIONCOMPONENT_H
#define GAME_POSITIONCOMPONENT_H


#include "Components.h"

class PositionComponent : public Component{
private:
    int xpos;
    int ypos;
public:
    PositionComponent(){
        xpos = 0;
        ypos = 0;
    }

    PositionComponent(int x, int y){
        xpos = x;
        ypos = y;
    }

    int x() const { return xpos; }
    int y() const { return ypos; }

    void update() override{
        xpos++;
        ypos++;
    }

    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }
};


#endif //GAME_POSITIONCOMPONENT_H
