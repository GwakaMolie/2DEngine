#pragma once
#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class AnimatedGraphic : public SDLGameObject{

public:
    AnimatedGraphic();
    ~AnimatedGraphic();
    
    void update();
    void render();
    void clean();
    void load(const LoaderParams* pParmas);

private:

    int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator {

  GameObject* createGameObject() const {

    return new AnimatedGraphic();
  }
};