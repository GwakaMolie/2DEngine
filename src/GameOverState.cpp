#include "GameOverState.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "MenuButton.hpp"
#include "AnimatedGraphic.hpp"
#include "PlayState.hpp"
#include "TextureManager.hpp"
#include "StateParser.hpp"

std::string GameOverState::s_gameOverID = "GAMEOVER";


void GameOverState::update() {
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }

}

void GameOverState::render() {
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->render();
    }

}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks) {

    // go through the game objects
    for(unsigned int i = 0; i < m_gameObjects.size(); i++) {
        // if they are of type MenuButton then assign a callback based on the id passed in from the file
        if(dynamic_cast<MenuButton*>(m_gameObjects[i])) {
            MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
  }
}

bool GameOverState::onEnter() {
    StateParser stateParser;
    stateParser.parseState("assets/test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);

    m_callbacks.push_back(0);
    m_callbacks.push_back(s_gameOverToMain);
    m_callbacks.push_back(s_restartPlay);

    // set the callbacks for menu items
    setCallbacks(m_callbacks);

    std::cout << "entering PauseState\n";
    return true;
}

bool GameOverState::onExit() {
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }

    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
    }

    m_gameObjects.clear();
    
    std::cout << "Exiting PauseState\n";
    return true;
}


void GameOverState::s_gameOverToMain() {

    TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay() {

    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}