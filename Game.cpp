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
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto & tile2(manager.addEntity());

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

    tile0.addComponent<TileComponent>(200,200,32,32,0);
    tile1.addComponent<TileComponent>(250,250,32,32,1);
    tile1.addComponent<ColliderComponent>("dirt");
    tile2.addComponent<TileComponent>(150,150,32,32,1);
    tile2.addComponent<ColliderComponent>("grass");


    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("../Assets/player.png");
    player.addComponent<KeyBoardController>();
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("../Assets/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
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
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)){
       player.getComponent<TransformComponent>().scale = 1;
        player.getComponent<TransformComponent>().velocity * -1;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    //TODO: stuff to render

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


