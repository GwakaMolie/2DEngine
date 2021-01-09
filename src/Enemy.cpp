#include <SDL2/SDL.h>
#include "Enemy.hpp"
#include <math.h>


Enemy::Enemy() : SDLGameObject() {};

void Enemy::load(const LoaderParams* pParmas){
    SDLGameObject::load(pParmas);
    m_velocity.setY(2);
}

Enemy::~Enemy(){};

void Enemy::render(){
    SDLGameObject::render();

}

void Enemy::update(){

    this->m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames ));

    m_acceleration.setX(0.1f);
    m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

    if(m_position.getY() < 0) {
        m_velocity.setY(2);
    }

    else if(m_position.getY() > 600 - this->m_width) {
        m_velocity.setY(-2);
    }

    

  SDLGameObject::update();
}

void Enemy::clean(){

}