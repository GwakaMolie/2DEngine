#include "PauseState.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "TextureManager.hpp"
#include "MenuButton.hpp"
#include "InputHandler.hpp"
#include "StateParser.hpp"

std::string PauseState::s_PauseID = "PAUSE";

void PauseState::render(){ 
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->render();
    }
}

void PauseState::update(){ 

    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

bool PauseState::onEnter(){ 
    StateParser stateParser;
    stateParser.parseState("assets/test.xml", s_PauseID, &m_gameObjects, &m_textureIDList);

    m_callbacks.push_back(0);
    m_callbacks.push_back(s_pauseToMain);
    m_callbacks.push_back(s_resumePlay);

    setCallbacks(m_callbacks);

    std::cout << "Entering Pause Menu \n";

    return true;
    
}

bool PauseState::onExit(){ 
    for(unsigned int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }

    // clear the texture manager
    for(unsigned int i = 0; i < m_textureIDList.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
    }

    m_gameObjects.clear();

    // reset the mouse button states to false
    TheInputHandler::Instance()->reset();

    std::cout << "Exiting Pause Menu \n";
    return true;

}
void PauseState::setCallbacks(const std::vector<Callback>& callbacks) {

    // go through the game objects
    for(unsigned int i = 0; i < m_gameObjects.size(); i++) {

        // if they are of type MenuButton then assign a callback based on the id passed in from the file
        if(dynamic_cast<MenuButton*>(m_gameObjects[i])) {
            MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }

}

void PauseState::s_resumePlay(){
    TheGame::Instance()->getStateMachine()->popState();

}

void PauseState::s_pauseToMain(){
    TheGame::Instance()->getStateMachine()->pushState(new MainMenuState());
}

std::string PauseState::getStateID() const {
    return this->s_PauseID;
}