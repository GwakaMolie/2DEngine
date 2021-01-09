#pragma once 

#include <SDL2/SDL.h>
#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class Enemy : public SDLGameObject{

public:
    Enemy();
    ~Enemy();

    void update();
    void render();
    void load(const LoaderParams* pParmas);
    void clean();

};

class EnemyCreator : public BaseCreator {

  GameObject* createGameObject() const {

    return new Enemy();
  }
};