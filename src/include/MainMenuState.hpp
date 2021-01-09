#pragma once

#include "MenuState.hpp"
#include "GameObject.hpp"
#include <vector>

class MainMenuState :  public MenuState {

public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const ;

private:
    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    static std::string s_MainMenuID;
    std::vector<GameObject*> m_gameObjects;
    
    static void s_menuToPlay();
    static void s_exitFromMenu();

};
