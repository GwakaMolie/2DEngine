#include <SDL2/SDL.h>
#include "LoaderParams.hpp"
#include "GameObject.hpp"


void GameObject::update() {};
void GameObject::render() {};
void GameObject::clean() {};
void GameObject::load(const LoaderParams* pParams) {};

GameObject::GameObject() {};
GameObject::~GameObject() {};
