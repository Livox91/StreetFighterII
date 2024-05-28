#include "./Universal.h"
#include "./HealthBar.h"
#include "./Points.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    HealthBar *health;
    Points *Score;
    sf::Texture textureIdle;
    sf::Texture textureJump;
    sf::Texture textureCrouch;
    sf::Texture texturePunch;
    sf::Sprite sprite;
    std::string spritesheet;
    float width;
    float height;
    float xpos;
    float dx;
    float ypos;

public:
    Player(std::string image) : spritesheet(image){};
    virtual void play(sf::Event e, float dt) = 0;
    void draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        window->draw(this->sprite);
        this->health->draw(window);
        this->Score->draw(window);
    }
};

#endif