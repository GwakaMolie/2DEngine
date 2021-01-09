#pragma once

#include "GameState.hpp"
#include "GameObject.hpp"
#include <vector>
#include "SDLGameObject.hpp"
#include "Level.hpp"


class PlayState : public GameState {

public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const;

private:

    Level *pLevel;

    bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
    static std::string s_PlayID;
    std::vector<GameObject*> m_gameObjects;

};