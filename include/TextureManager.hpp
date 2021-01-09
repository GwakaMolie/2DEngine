#pragma once
#include <SDL2/SDL.h>
#include <map>
#include <string>


class TextureManager {

public:

    static TextureManager* Instance();

    bool LoadTexture(std::string PathToTexture, std::string ID);
    void draw(std::string ID, int x, int y, int width, int height, SDL_RendererFlip flip);
    void drawFrame(std::string ID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void clearFromTextureMap(std::string ID);
    void drawTile(std::string id, int margin, int spacing, int x, int y, 
    int width, int height, int currentRow,  int currentFrame) ;

    static std::map <std::string, SDL_Texture*> textureMap;
    static TextureManager* s_pInstance;

private:
    TextureManager();
};

typedef TextureManager TheTextureManager;