#include "../header/Background.h"

Background::Background(sf::RenderWindow *renderWindow, std::string spritesheet)
{
    this->spritesheet = spritesheet;
    this->window = renderWindow;
    if (!(this->TextureBg0.loadFromFile(spritesheet, sf::IntRect(50, 0, 417, 225)) &&
          this->TextureBg1.loadFromFile(spritesheet, sf::IntRect(0, 240, 329, 185))))
    {
        std::cout << "Eroor";
    }
    background0.setTexture(this->TextureBg0);
    background1.setTexture(this->TextureBg1);
    background0.setScale(2, 3);
    background1.setScale(1.5, 1.5);
    background1.setPosition(300, 200);
}

void Background::draw()
{
    this->window->draw(background0);
    this->window->draw(background1);
}