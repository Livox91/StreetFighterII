#include "./Universal.h"

#ifndef SELECTION_H
#define SELECTION_H

class SelectionScreen
{
private:
    sf::Texture texture;
    std::string spritesheet;
    sf::Sprite sprite;

public:
    SelectionScreen(std::string spritesheet)
    {
        this->spritesheet = spritesheet;
        if (!this->texture.loadFromFile(this->spritesheet, sf::IntRect(197, 5, 251, 214)))
        {
            std::cout << "Error";
        }
        this->sprite.setTexture(this->texture);
        this->sprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4));
        this->sprite.setScale(sf::Vector2f(2.0, 2.0));
    };
    void draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        window->draw(this->sprite);
    }
};

#endif