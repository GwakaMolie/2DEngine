#pragma once

#include "GameState.hpp"
#include <vector>

class GameStateMachine {

public:

    void update();
    void render();
    void clean();

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();


private:
    std::vector<GameState*> m_gameStates;
};