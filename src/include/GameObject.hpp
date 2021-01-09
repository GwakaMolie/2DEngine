#pragma once 

#include <SDL2/SDL.h>
#include "LoaderParams.hpp"

class GameObject {

public:

    virtual ~GameObject() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void clean() = 0;
    virtual void load(const LoaderParams* pParams) = 0;

protected:

    GameObject();

};