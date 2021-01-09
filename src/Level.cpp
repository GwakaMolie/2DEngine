#include "Level.hpp"

Level::Level() {

}

void Level::render() {

  for(long unsigned int i = 0; i < m_layers.size(); i++) {
    m_layers[i]->render();
  }
}

void Level::update() {

  for(long unsigned int i = 0; i < m_layers.size(); i++) {
    m_layers[i]->render();
  }
}