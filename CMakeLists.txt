cmake_minimum_required(VERSION 3.24)
project(Game)

set(CMAKE_APPLE_SILICON_PROCESS, arm64)
set(CMAKE_OSX_ARCHITECTURES, arm64)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf REQUIRED)



include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})


add_executable(Game main.cpp Game.cpp Game.h TextureManager.cpp TextureManager.h GameObject.cpp GameObject.h Map.cpp Map.h ECS/ECS.h ECS/Components.h ECS/TransformComponent.h ECS/SpriteComponent.h ECS/Vector2D.h ECS/Vector2D.cpp ECS/KeyBoardController.h ECS/ColliderComponent.cpp ECS/ColliderComponent.h ECS/Collision.h ECS/Collision.cpp ECS/TileComponent.h ECS/ECS.cpp ECS/Animation.h ECS/ProjectileComponent.h AssetManager.cpp AssetManager.h ECS/UILabel.h)
target_link_libraries(Game  ${SDL2_LIBRARIES}    SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)

