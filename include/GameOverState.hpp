#pragma once

#include "MenuState.hpp"
#include "GameObject.hpp"
#include <vector>

class GameOverState : public MenuState {

public:

    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {return s_gameOverID;}
    virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:
    static void s_gameOverToMain();
    static void s_restartPlay();

    std::vector<GameObject*> m_gameObjects;
    static std::string s_gameOverID;
};