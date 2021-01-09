#include "InputHandler.hpp"
#include <iostream>
#include "Game.hpp"
#include "Vector2D.hpp"

InputHandler::InputHandler(){}
InputHandler::~InputHandler(){}

InputHandler* InputHandler::s_pInstance = nullptr;

InputHandler* InputHandler::Instance(){

    if(s_pInstance == 0) {

        s_pInstance = new InputHandler();
    }
    return s_pInstance;

}

void InputHandler::init(){
    this->m_mousePosition = new Vector2D();

    for (int i = 0; i < 3; i++) {
        this->m_mouseButtonStates.push_back(false);
    }
    m_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::update(){
    SDL_Event event;


    while(SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            TheGame::Instance()->quit();
            break;

        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;

        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;

        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event); 
            break;

        case SDL_KEYDOWN:
            onKeyDown();
            break;

        case SDL_KEYUP:
            onKeyUp();
            break;

        default:
            break;
        }
    }
}

void InputHandler::onMouseButtonDown(SDL_Event& event){

    if(event.button.button == SDL_BUTTON_LEFT){
        this->m_mouseButtonStates[LEFT] = true;
    }

    if(event.button.button == SDL_BUTTON_MIDDLE){
        this->m_mouseButtonStates[MIDDLE] = true;
    }

    if(event.button.button == SDL_BUTTON_RIGHT){
        this->m_mouseButtonStates[RIGHT] = true;
    }
}
void InputHandler::onMouseButtonUp(SDL_Event& event){

    if(event.button.button == SDL_BUTTON_LEFT){
        this->m_mouseButtonStates[LEFT] = false;
    }

    if(event.button.button == SDL_BUTTON_MIDDLE){
        this->m_mouseButtonStates[MIDDLE] = false;
    }

    if(event.button.button == SDL_BUTTON_RIGHT){
        this->m_mouseButtonStates[RIGHT] = false;
    }

}

void InputHandler::onMouseMove(SDL_Event& event){


    this->m_mousePosition->setX(event.motion.x);
    this->m_mousePosition->setY(event.motion.y);
}

bool InputHandler::getMouseButtonState(int buttonNumber){
  return this->m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition(){
    return this->m_mousePosition;
}

void InputHandler::onKeyDown(){
    // this->m_keystates = SDL_GetKeyboardState(0);

}

void InputHandler::onKeyUp(){
    // this->m_keystates = SDL_GetKeyboardState(0);
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    if(m_keystate != 0) {
        if(m_keystate[key] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void InputHandler::reset(){
    this->m_mouseButtonStates = {0, 0, 0};
}

void InputHandler::clean(){

}