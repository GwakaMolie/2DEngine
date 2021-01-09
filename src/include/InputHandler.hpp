#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.hpp"

class InputHandler {

public:

    static InputHandler* Instance(); 

    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();

    // handling keyboard events
    bool isKeyDown(SDL_Scancode key);

    void update();
    void clean();
    void init();
    void reset();

private:
    InputHandler();
    ~InputHandler();

    static InputHandler* s_pInstance;

    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;

    const Uint8* m_keystate = SDL_GetKeyboardState(NULL);

    void onKeyDown();
    void onKeyUp();

    void onMouseButtonUp(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseMove(SDL_Event& event);

}; 
enum mouse_buttons{ LEFT = 0, MIDDLE = 1, RIGHT = 2 };
typedef InputHandler TheInputHandler;