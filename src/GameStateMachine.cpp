#include "GameStateMachine.hpp"

void GameStateMachine::pushState(GameState* pState) {
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
};

void GameStateMachine::changeState(GameState* pState) {
    if(!m_gameStates.empty()){
        if(m_gameStates.back()->getStateID() == pState->getStateID()){
            return;
        }
        if(m_gameStates.back()->onExit()){
            m_gameStates.pop_back();
        }
    }
    // pushing the new element
    m_gameStates.push_back(pState);
    pState->onEnter();

};

void GameStateMachine::popState() {
    if(!m_gameStates.empty()){

        if(m_gameStates.back()->onExit()){

            delete m_gameStates.back();
            m_gameStates.back() = NULL;
            m_gameStates.pop_back();

        }
    }
};

void GameStateMachine::update() {
    if(!m_gameStates.empty()) {
        m_gameStates.back()->update();
    }
}

void GameStateMachine::render() {
    if(!m_gameStates.empty()) {
        m_gameStates.back()->render();
    }
}

void GameStateMachine::clean() {
    if(!m_gameStates.empty()) {
       m_gameStates.back()->onExit();
        delete m_gameStates.back();
        m_gameStates.clear(); 
    }
}

