#include "./Universal.h"

#ifndef SELECTION_H
#define SELECTION_H

class SelectionScreen
{
private:
    sf::Texture texture;
    std::string spritesheet;
    sf::Sprite sprite;
    sf::Text text;
    sf::Font fonts;

public:
    SelectionScreen(std::string spritesheet)
    {
        if (!this->fonts.loadFromFile(font))
        {
            std::cout << "Error";
        }
        this->text.setFont(fonts);
        this->text.setString("PRESS H TO START");
        this->text.setFillColor(sf::Color::White);
        this->text.setCharacterSize(26);
        this->text.setPosition(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT - 20));

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
        window->draw(this->text);
    }
};

#endif