#pragma once 

#include <SDL2/SDL.h>
#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"
#include "GameObjectFactory.hpp"

class Player : public SDLGameObject{
public:
    Player();
    ~Player();

    void update();
    void render();
    void clean();
    void load(const LoaderParams* pParmas);

private:
    void handleInput();
};

class PlayerCreator : public BaseCreator {

  GameObject* createGameObject() const {

    return new Player();
  }
};