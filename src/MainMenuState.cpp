#include "MainMenuState.hpp"
#include "PlayState.hpp"
#include "MenuButton.hpp"
#include "TextureManager.hpp"
#include "LoaderParams.hpp"
#include "StateParser.hpp"
#include "Game.hpp"
#include <iostream>

std::string MainMenuState::s_MainMenuID = "MENU";

void MainMenuState::update(){
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
};

void MainMenuState::render(){
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->render();
    } 
};

bool MainMenuState::onEnter(){

    StateParser stateParser;
    stateParser.parseState("assets/test.xml", s_MainMenuID, &m_gameObjects, &m_textureIDList); 

    

    m_callbacks.push_back(0); //pushback 0 callbackID start from 1
    m_callbacks.push_back(s_menuToPlay);
    m_callbacks.push_back(s_exitFromMenu);

    setCallbacks(m_callbacks);

    std::cout << "Entering MainMenuState\n";
    return true;
};

bool MainMenuState::onExit(){

    // clear the texture manager
    for(unsigned int i = 0; i < m_textureIDList.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
    }

    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();

    std::cout << "Exiting MenuState\n";
    
    return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks) {

    // go through the game objects
    for(unsigned int i = 0; i < m_gameObjects.size(); i++) {
        // if they are of type MenuButton then assign a callback based on the id passed in from the file
        if(dynamic_cast<MenuButton*>(m_gameObjects[i])) {
            MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
  }
}

void MainMenuState::s_menuToPlay() {

    std::cout << "Play button clicked\n";
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu() {

    std::cout << "Exit button clicked\n";
    Game::Instance()->quit();
};

std::string MainMenuState::getStateID() const {
    return this->s_MainMenuID;
}