//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "iostream"

class Map {
public:
    Map();
    ~Map();

    static void LoadMap(std::string path, int sizeX, int sizeY);
    void DrawMap();
private:


    int map[20][25];
};


#endif //GAME_MAP_H
