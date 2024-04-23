#include "./Universal.h"
#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
private:
    std::string spritesheet;
    sf::RenderWindow *window;
    sf::Texture TextureBg0;
    sf::Texture TextureBg1;
    sf::Sprite background0;
    sf::Sprite background1;

public:
    Background(sf::RenderWindow *renderWindow, std::string spritesheet);
    void draw();
};
#endif