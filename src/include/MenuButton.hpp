#pragma once
#include "MenuButton.hpp"
#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class MenuButton : public SDLGameObject {

public:
    MenuButton();

    virtual void render();
    virtual void update();
    virtual void clean();
    virtual void load(const LoaderParams* pParams);

    int getCallbackID() { return m_callbackID; }
    void setCallback(void(*callback)()) { m_callback = callback;}

private:

    int m_callbackID;
    bool m_released;
    void (*m_callback)();

    enum button_state { MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2 };

};

class MenuButtonCreator : public BaseCreator {

  GameObject* createGameObject() const {

    return new MenuButton();
  }
};