#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Enemy.hpp"
#include "GameStateMachine.hpp"


class Game {
public:
    ~Game();

    static Game* Instance();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    bool running();

    void handleEvents();
    void update();
    void render();
    void quit();
    void clean();
    SDL_Renderer* getRenderer () const ;
    GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }

    int getGameWidth() const {return m_gameWidth;}
    int getGameHeight() const {return m_gameHeight;}

private:


    Game();
    static Game* s_pInstance;
    SDL_Renderer* m_pRenderer;

    std::vector<GameObject*> m_gameObjects;
    SDL_Window* window;
    bool isRunning;

    int m_gameWidth;
    int m_gameHeight;

    GameObject *m_player1;
    GameObject *m_go;
    GameObject *m_enemy;

    GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;
