#include "MenuButton.hpp"
#include <iostream>
#include "InputHandler.hpp"

MenuButton::MenuButton() : SDLGameObject() {

}

void MenuButton::load(const LoaderParams* pParams){
    SDLGameObject::load(pParams);
    this->m_callbackID = pParams->getCallBackID();
    this->m_currentFrame = MOUSE_OUT;
}

void MenuButton::render(){
    SDLGameObject::render();
};

void MenuButton::update(){

    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if(pMousePos->getX() < (m_position.getX() + m_width) && pMousePos->getX() > m_position.getX() &&
    pMousePos->getY() < (m_position.getY() + m_height) && pMousePos->getY() > m_position.getY()) {

        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_released) {
            m_currentFrame = CLICKED;
            if(m_callback != 0) {
                m_callback();
            }
            
            m_released = false;
        }
        else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
            m_released = true;
            m_currentFrame = MOUSE_OVER;
        }

    } else{
        m_currentFrame = MOUSE_OUT;
    }
};

void MenuButton::clean(){
    SDLGameObject::clean();

};