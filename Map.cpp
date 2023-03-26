//
// Created by Rostyslav on 25.03.2023.
//

#include "Map.h"
#include "TextureManager.h"
#include "iostream"
#include "Game.h"
#include "fstream"


Map::Map() {

}

Map::~Map() {

}



void Map::LoadMap(std::string path, int sizeX, int sizeY) {
    char c;
    std::fstream mapFile;
    mapFile.open(path);

    int srcX, srcY;

    for(int y = 0; y < sizeY; y++){
        for(int x = 0; x < sizeX; x++){
            mapFile.get(c);
            srcY = atoi(&c) * 32;
            mapFile.get(c);
            srcX = atoi(&c) * 32;
            Game::AddTile(srcX, srcY, x * 64, y * 64);
            mapFile.ignore();
        }
    }
    mapFile.close();
}

