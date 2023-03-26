//
// Created by Rostyslav on 25.03.2023.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "iostream"

#include <string>

class Map
{
public:

    Map(std::string tID, int ms, int ts);
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);
    void AddTile(int srcX, int srcY, int xpos, int ypos);

private:
    std::string texID;
    int mapScale;
    int tileSize;
    int scaledSize;

};


#endif //GAME_MAP_H
