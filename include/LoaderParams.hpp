#pragma once
#include <string>

class LoaderParams {

public:
    LoaderParams(int x, int y, int width, int height, std::string textureID,
    int numFrames, int callBackID = 0, int animSpeed = 0);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    int getNumFrames() const;
    int getCallBackID() const;
    int getAnimSpeed() const;

    std::string getTextureID() const;

private:

    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_textureID;
    int  m_numFrames;
    int  m_callBackID;
    int  m_animSpeed;
};