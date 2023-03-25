//
// Created by Rostyslav on 25.03.2023.
//

#include "Map.h"
#include "TextureManager.h"

int level1[20][25] = { {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,1, 1,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,2, 2,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 2,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 2,1, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 2,2, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 2,2, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 3,2, 2,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0},
                       {0,0, 1,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0, 0,0,0}
                       };

Map::Map() {
    dirt = TextureManager::LoadTexture("../Assets/dirt.png");
    grass = TextureManager::LoadTexture("../Assets/grass.png");
    water = TextureManager::LoadTexture("../Assets/water.png");
    LoadMap(level1);
    src.x = src.y = 0;
    src.w = src.h = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map() {

}

void Map::DrawMap() {
    int type = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 25; j++){
            type = map[i][j];
            dest.x = j * 32;
            dest.y = i * 32;
            switch (type) {
                case 0:
                    TextureManager::Draw(water, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(grass, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(dirt, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}

void Map::LoadMap(int arr[20][25]) {
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 25; j++){
            map[i][j] = arr[i][j];
        }
    }
}
