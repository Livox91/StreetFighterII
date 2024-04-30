#include "./Universal.h"

#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

class HealthBar
{
    sf::RenderWindow *window;
    sf::RectangleShape rectangle;
    float dmg;
    int id;
    float width;
    float height;

public:
    HealthBar(sf::RenderWindow *renderWindow, float xpos, float ypos, float width, float height, sf::Color color, int id)
    {
        this->id = id;
        this->window = renderWindow;
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
    void draw()
    {
        this->window->draw(this->rectangle);
    }
};

#endif