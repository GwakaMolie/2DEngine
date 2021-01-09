#include "PlayState.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "InputHandler.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "StateParser.hpp"
#include "LevelParser.hpp"

#include <iostream>

std::string PlayState::s_PlayID = "PLAY";

void PlayState::update(){


    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for (unsigned int i = 0; i < this->m_gameObjects.size(); i++) {
        this->m_gameObjects[i]->update();
    }

    pLevel->update();

//     if(checkCollision(dynamic_cast<SDLGameObject*> (m_gameObjects[0]), 
//     dynamic_cast<SDLGameObject*> (m_gameObjects[1]))) {

//     TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
//   }
};

void PlayState::render(){
    for (unsigned int i = 0; i < this->m_gameObjects.size(); i++) {
        this->m_gameObjects[i]->render();
    }
    pLevel->render();

};

bool PlayState::onEnter(){
    // StateParser stateParser;
    // stateParser.parseState("assets/test.xml", s_PlayID, &m_gameObjects, &m_textureIDList);

    LevelParser levelParser;
    pLevel = levelParser.parseLevel("assets/map1.tmx");


    std::cout << "Entering PlayState.\n";
    return true;
};

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2){

    //Calculate the sides of rect A
    int leftA = p1->getPosition().getX();
    int rightA = p1->getPosition().getX() + p1->getWidth();
    int topA = p1->getPosition().getY();
    int bottomA = p1->getPosition().getY() + p1->getHeight();
    //Calculate the sides of rect B
    
    int leftB = p2->getPosition().getX();
    int rightB = p2->getPosition().getX() + p2->getWidth();
    int topB = p2->getPosition().getY();
    int bottomB = p2->getPosition().getY() + p2->getHeight();

    //If any of the sides from A are outside of B
    if( bottomA <= topB ){return false;} 
    if( topA >= bottomB ){return false; }
    if( rightA <= leftB ){return false; }
    if( leftA >= rightB ){return false;}

    return true;
}

bool PlayState::onExit(){
    // clear the texture manager
    for(unsigned int i = 0; i < m_textureIDList.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
    }

    for(unsigned int i = 0; i < m_gameObjects.size(); i++) {
        this->m_gameObjects[i]->clean();
    }
    this->m_gameObjects.clear();

    std::cout << "Exiting PlayState.\n";
    return true;
};

std::string PlayState::getStateID() const {
    return this->s_PlayID;
}