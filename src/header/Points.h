#include "./Universal.h"

#ifndef POINTS_H
#define POINTS_H

class Points
{
private:
    int points;
    sf::Sprite sprite;
    sf::Texture texture0;
    sf::Texture texture3;
    sf::Texture texture2;
    sf::Texture texture1;
    float xpos;
    float ypos;
    int id;

public:
    Points(float xpos, float ypos, int id, std::string spritesheet)
    {
        this->xpos = xpos;
        this->ypos = ypos;
        if (!this->texture0.loadFromFile(spritesheet, sf::IntRect(106, 238, 13, 25)))
        {
            std::cout << "Eroor";
        }
        if (!this->texture1.loadFromFile(spritesheet, sf::IntRect(14, 238, 13, 25)))
        {
            std::cout << "Eroor";
        }
        if (!this->texture2.loadFromFile(spritesheet, sf::IntRect(25, 238, 13, 25)))
        {
            std::cout << "Eroor";
        }
        if (!this->texture3.loadFromFile(spritesheet, sf::IntRect(35, 238, 13, 25)))
        {
            std::cout << "Eroor";
        }
        this->sprite.setTexture(texture3);
        this->sprite.setTexture(texture0);
        this->sprite.setPosition(this->xpos, this->ypos);
        this->sprite.setScale(sf::Vector2f(2.0, 2.0));
        this->points = 0;
        this->id = id;
    }
    void increment()
    {
        if (this->sprite.getTexture() == &this->texture0)
        {
            this->sprite.setTexture(texture1);
            points = 1;
        }
        else if (this->sprite.getTexture() == &this->texture1)
        {
            this->sprite.setTexture(texture2);
            points = 2;
        }
        else if (this->sprite.getTexture() == &this->texture2)
        {
            this->sprite.setTexture(texture3);
            points = 3;
        }
    }
    int getPoints()
    {
        return this->points;
    }
    void draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        window->draw(this->sprite);
    }
};
#endif