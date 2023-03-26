//
// Created by Rostyslav on 24.03.2023.
//

#include "Game.h"
#include "iostream"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "ECS/ECS.h"
#include "ECS/SpriteComponent.h"
#include "ECS/Collision.h"
#include "ECS/ColliderComponent.h"


Map* map;
Manager manager;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
enum groupLabels : std::size_t{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};


Game::~Game() {

}

Game::Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std:: cout << "Subsystem initialized!..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"Window created";
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Rendered successfully" << std::endl;
        }
        isRunning = true;
    }else{
        isRunning = false;
        std::cout << "Initialized incorrect"<<std::endl;
    }

    map = new Map();
    Map::LoadMap("../Assets/pixel16*16.txt", 16, 16);

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("../Assets/player_idle.png", 4, 200);
    player.addComponent<KeyBoardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

}

void Game::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    //TODO:game)
    cnt++;
    manager.update();
    manager.refresh();
    for(auto cc : colliders){
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));


void Game::render() {
    SDL_RenderClear(renderer);
    for(auto& t : tiles){
        t->draw();
    }
    for(auto& p : players){
        p->draw();
    }

    for(auto& e : enemies){
        e->draw();
    }

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<< "Game cleaned";
}

bool Game::running() {
    return isRunning;
}

void Game::AddTile(int id, int x, int y) {
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupMap);
}


