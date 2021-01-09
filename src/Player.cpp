#include <SDL2/SDL.h>
#include "Player.hpp"
#include "InputHandler.hpp"
#include "TextureManager.hpp"


Player::Player() : SDLGameObject(){

}

void Player::load(const LoaderParams* pParmas){
    SDLGameObject::load(pParmas);

}

Player::~Player(){};

void Player::render(){
    if(m_velocity.getX() > 0) {
    TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), 
    m_width, m_height, m_currentRow, m_currentFrame, SDL_FLIP_HORIZONTAL);
    }
  else {
    TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), 
    m_width, m_height, m_currentRow, m_currentFrame);
    }
}

void Player::update(){


    handleInput();

    this->m_currentFrame = int(((SDL_GetTicks() / 100) % 5 ));
    this->m_currentRow = 1; 
   
    SDLGameObject::update();
}

void Player::handleInput(){

    m_velocity.setX(0);
    m_velocity.setY(0);
    Vector2D* target = TheInputHandler::Instance() ->getMousePosition();
    m_velocity = *target - m_position;
    m_velocity /= 30;

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_velocity.setX(6);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_velocity.setX(-6);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setY(-6);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)){
        m_velocity.setY(6);
    }
    
}

void Player::clean(){

}
