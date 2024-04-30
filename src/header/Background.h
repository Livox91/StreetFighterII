#include "./Universal.h"
#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
private:
    std::string spritesheet1;
    std::string spritesheet2;
    sf::RenderWindow *window;
    sf::Texture TextureBg0;
    sf::Texture TextureBg1;
    sf::Texture TextureBg2;
    sf::Sprite background0;
    sf::Sprite background1;
    sf::Sprite HealthBar;

public:
    Background() {}
    Background(sf::RenderWindow *renderWindow, std::string spritesheet1, std::string spritesheet2)
    {
        this->spritesheet1 = spritesheet1;
        this->spritesheet2 = spritesheet2;
        this->window = renderWindow;
        if (!(this->TextureBg0.loadFromFile(spritesheet1, sf::IntRect(50, 0, 417, 225)) &&
              this->TextureBg1.loadFromFile(spritesheet1, sf::IntRect(0, 240, 329, 185)) &&
              this->TextureBg2.loadFromFile(spritesheet2, sf::IntRect(30, 11, 195, 13))))
        {
            std::cout << "Eroor";
        }
        background0.setTexture(this->TextureBg0);
        background1.setTexture(this->TextureBg1);
        HealthBar.setTexture(this->TextureBg2);
        background0.setScale(2, 3);
        background1.setScale(1.5, 1.5);
        HealthBar.setScale(sf::Vector2f(2.0, 2.0));
        background1.setPosition(300, 200);
        HealthBar.setPosition(SCREEN_WIDTH / 2 - 200, 10);
    }
    void draw()
    {
        this->window->draw(background0);
        this->window->draw(background1);
        this->window->draw(HealthBar);
    }
};
#endif