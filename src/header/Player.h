#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    sf::RenderWindow *window;
    sf::Event *e;
    sf::Texture textureIdle;
    sf::Texture textureJump;
    sf::Texture textureCrouch;
    sf::Texture texturePunch;
    sf::Texture textureKick;
    sf::Sprite sprite;
    std::string spritesheet;
    float width;
    float height;
    float xpos;
    float dx;
    float ypos;

public:
    Player();
    Player(sf::RenderWindow *renderWindow, std::string image);
    void play(float dt);
    void draw();
};

#endif