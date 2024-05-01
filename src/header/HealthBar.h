#include "./Universal.h"

#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

class HealthBar
{
    sf::RectangleShape rectangle;
    int health;
    float dmg;
    int id;
    float width;
    float widthInit;
    float healthInit;
    float height;

public:
    HealthBar(float xpos, float ypos, float width, float height, sf::Color color, int id)
    {
        this->health = 183;
        this->healthInit = 183;
        this->id = id;
        this->widthInit = width;
        this->width = width;
        this->height = height;
        this->dmg = 5;
        this->rectangle.setSize(sf::Vector2f(this->width, this->height));
        rectangle.setFillColor(color);
        rectangle.setPosition(sf::Vector2f(xpos, ypos));
    }
    void damage()
    {
        this->width -= 5;
        this->health -= 5;
        if (this->width <= -183 && this->id == 2)
        {
            this->width = -183;
        }
        if (this->width <= 0 && this->id == 1)
        {
            this->width = 0;
        }
        this->rectangle.setSize(sf::Vector2f(this->width, this->height));
    }
    int getHealth()
    {
        return this->health;
    }
    void draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        window->draw(this->rectangle);
    }
    void reset()
    {
        this->width = this->widthInit;
        this->health = this->healthInit;
        this->rectangle.setSize(sf::Vector2f(this->width, this->height));
    }
};

#endif