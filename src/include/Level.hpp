#pragma once 

#include <string>
#include <vector>

#include "Layer.hpp"

struct Tileset {
    int firstGridID;
    int tileWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    std::string name;
};

class Level {

public:
    ~Level() {}

    void update();
    void render();

    std::vector<Tileset>* getTilesets(){return &m_tilesests;};
    std::vector<Layer*>* getLayers(){return &m_layers;};

private:
    friend class LevelParser;
    Level();

    std::vector<Tileset> m_tilesests;
    std::vector<Layer*> m_layers;
};