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
    char tile;
    std::fstream mapFile;
    mapFile.open(path);
    //TODO:Map parsing
    for(int y = 0; y < sizeY; y++){
        for(int x = 0; x < sizeX; x++){
            mapFile.get(tile);
            std::cout << tile;
            Game::AddTile(atoi(&tile), x * 32, y * 32);
            mapFile.ignore();
        }
    }
    mapFile.close();
}

