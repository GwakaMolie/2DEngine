#include "Layer.hpp"
#include "GameObject.hpp"
#include <vector>

class ObjectLayer : public Layer {
    
public:
    virtual void update();
    virtual void render();
    std::vector<GameObject*>* getGameObjects()  { return &m_gameObjects; }

private:
    std::vector<GameObject*> m_gameObjects;
};