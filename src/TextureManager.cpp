#include "TextureManager.hpp"
#include <SDL2/SDL_image.h>
#include "Game.hpp"
#include <string>
  
std::map<std::string, SDL_Texture*> TextureManager::textureMap;

TextureManager* TextureManager::s_pInstance = nullptr;

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y, 
int width, int height, int currentRow,  int currentFrame) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(Game::Instance()->getRenderer(), TextureManager::textureMap[id], &srcRect, &destRect, 0, 0 ,SDL_FLIP_NONE);
}

TextureManager::TextureManager(){};

TextureManager* TextureManager::Instance(){
    if(s_pInstance == 0){
        s_pInstance = new TextureManager();
        return s_pInstance;
    }
    return s_pInstance;
}

bool TextureManager::LoadTexture(std::string PathToTexture, std::string ID){
    
    PathToTexture = "assets/" + PathToTexture;

    SDL_Surface* tempSurf = IMG_Load(PathToTexture.c_str()); 
    if(tempSurf == 0)
    {
		std::cout << IMG_GetError();
        return false;
    }

    SDL_Texture* tempTextr = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), tempSurf);
    SDL_FreeSurface(tempSurf);

    if(tempTextr != 0){
        
        TextureManager::textureMap[ID] = tempTextr;

        return true; 
    }else 
        return false;
}

void TextureManager::draw(std::string ID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE){

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.h = height;
    srcRect.w = width;
    srcRect.x = 0;
    srcRect.y = 0;


    destRect.h = srcRect.h * 1;
    destRect.w = srcRect.w * 1;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(TheGame::Instance()->getRenderer(), TextureManager::textureMap[ID], &srcRect, &destRect,0 ,0, flip);
}

void TextureManager::drawFrame(std::string ID, int x, int y, int width, int height, 
int currentRow, int currentFrame, SDL_RendererFlip flip ){

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.h = height;
    srcRect.w = width;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);


    destRect.h = srcRect.h * 1;
    destRect.w = srcRect.w * 1;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(TheGame::Instance()->getRenderer(), TextureManager::textureMap[ID], 
    &srcRect, &destRect,0 ,0, flip);
}

void TextureManager::clearFromTextureMap(std::string ID){

    textureMap.erase(ID);

}