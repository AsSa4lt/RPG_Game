//
// Created by Rostyslav on 26.03.2023.
//
#include "ECS.h"

void Entity::addGroup(Group mGroup) {
    groupBitset[mGroup] = true;
    manager.AddToGroup(this, mGroup);
}

