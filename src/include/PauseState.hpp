#pragma once

#include "GameObject.hpp"
#include "MenuState.hpp"
#include <vector>
#include <iostream>

class PauseState :  public MenuState {

public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const ;
    virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:

    static std::string s_PauseID;
    std::vector<GameObject*> m_gameObjects;
    
    static void s_resumePlay();
    static void s_pauseToMain();

};