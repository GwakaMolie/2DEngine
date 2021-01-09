#include "SDLGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"

SDLGameObject::SDLGameObject(): GameObject() {}

SDLGameObject::~SDLGameObject(){}

void SDLGameObject::render(){

    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
    m_width, m_height, m_currentRow, m_currentFrame);
    
}
void SDLGameObject::update(){
    this->m_velocity += this->m_acceleration;
    this->m_position += this->m_velocity;
}
void SDLGameObject::clean(){
    delete this;
}

void SDLGameObject::load(const LoaderParams *pParams) {

    m_position = Vector2D(pParams->getX(),pParams->getY());
    m_velocity = Vector2D(0,0);
    m_acceleration = Vector2D(0,0);
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentRow = 1;
    m_currentFrame = 1;
    m_numFrames = pParams->getNumFrames();
}