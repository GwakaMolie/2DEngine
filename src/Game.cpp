#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "Game.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "InputHandler.hpp"

#include "MainMenuState.hpp"
#include "MenuButton.hpp"
#include "PlayState.hpp"
#include "GameOverState.hpp"
#include "GameObjectFactory.hpp"
#include "AnimatedGraphic.hpp"

Game::Game(){}
Game::~Game(){}

Game* Game::s_pInstance = nullptr;

Game* Game::Instance(){

    if(Game::s_pInstance == 0) { 
        Game::s_pInstance = new Game();
        return Game::s_pInstance;
    }
    return Game::s_pInstance;
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

    int flags  = 0;

    // if fullscreen is true change flags 
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    // setting w / h
    m_gameWidth = width;
    m_gameHeight = height;


    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        std::cout << "Video subsystem initilized." << std::endl;

        this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(this->window){
            std::cout << "Window Created" << std::endl;
        }
        
        this->m_pRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        if(this->m_pRenderer){
            SDL_SetRenderDrawColor(this->m_pRenderer, 0, 0, 0, 255);
            std::cout << "Renderer Created" << std::endl;
        }
        this->isRunning = true;
    }else{
        this->isRunning = false;
    }

    //Init Inputs 
    TheInputHandler::Instance()->init();

    //Registering types for factory
    GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    GameObjectFactory::Instance()->registerType("Player", new  PlayerCreator());
    GameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
    GameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());

    //Init gameState
    this->m_pGameStateMachine = new GameStateMachine();
    this->m_pGameStateMachine->changeState(new MainMenuState());
}

SDL_Renderer* Game::getRenderer() const {return this->m_pRenderer;}

bool Game::running(){return this->isRunning;}

void Game::handleEvents(){
    TheInputHandler::Instance()->update();
}


void Game::render(){
    SDL_RenderClear(this->getRenderer());
    //rendering states
    m_pGameStateMachine->render();
    // this is where to add things to the renderer
    SDL_RenderPresent(this->getRenderer());
}

void Game::update(){ 
    m_pGameStateMachine->update(); 
}

void Game::quit(){
    this->isRunning = false;
}

void Game::clean(){

    TheInputHandler::Instance()->clean();

    m_pGameStateMachine->clean();
    delete m_pGameStateMachine;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->m_pRenderer);
    SDL_Quit();            

    std::cout << "Game Cleaned Successfuly" << std::endl;
}