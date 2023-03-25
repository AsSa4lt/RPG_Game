//
// Created by Rostyslav on 24.03.2023.
//

#include "Game.h"
#include "iostream"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "ECS/ECS.h"
#include "ECS/SpriteComponents.h"


Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

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
    player.addComponent<PositionComponent>();
    player.addComponent<SpriteComponent>("../Assets/player.png");
}

void Game::handleEvents() {
    SDL_Event event;
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
}

void Game::render() {
    SDL_RenderClear(renderer);
    //TODO: stuff to render
    map->DrawMap();

    manager.draw();
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


