#include "./Universal.h"
#include "Player.h"
#include "Player2.h"
#ifndef PLAYER1_H
#define PLAYER1_H

class Player1 : public Player
{
public:
    Player1(std::string image, HealthBar *health) : Player(image)
    {
        if (!this->textureIdle.loadFromFile(spritesheet, sf::IntRect(18, 36, 39, 92)))
        {
            std::cout << "Error";
        }
        if (!this->textureJump.loadFromFile(spritesheet, sf::IntRect(729, 36, 36, 57)))
        {
            std::cout << "Error";
        }
        if (!this->textureCrouch.loadFromFile(spritesheet, sf::IntRect(89, 736, 44, 63)))
        {
            std::cout << "Error";
        }
        if (!this->texturePunch.loadFromFile(spritesheet, sf::IntRect(603, 1402, 65, 95)))
        {
            std::cout << "Error";
        }

        this->sprite.setTexture(this->textureIdle);
        this->width = this->sprite.getGlobalBounds().width;
        this->height = this->sprite.getGlobalBounds().height;
        this->xpos = 20;
        this->ypos = SCREEN_HEIGHT - this->height * 2;
        this->sprite.setPosition(sf::Vector2f(xpos, ypos));
        this->sprite.setScale(2, 2);
        this->health = health;
    }
    void play(sf::Event e, float dt) override
    {

        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.scancode == sf::Keyboard::Scan::D)
            {
                this->dx = 5;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(sf::Vector2f(xpos, ypos));
            }
            if (e.key.scancode == sf::Keyboard::Scan::W)
            {
                this->sprite.setTexture(this->textureJump);
                this->sprite.setPosition(sf::Vector2f(xpos + 50, ypos));
            }
            if (e.key.scancode == sf::Keyboard::Scan::S)
            {
                this->sprite.setTexture(this->textureCrouch);
                this->sprite.setPosition(sf::Vector2f(xpos, ypos + (this->height - 50)));
            }
            if (e.key.scancode == sf::Keyboard::Scan::A)
            {
                this->dx = -5;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(sf::Vector2f(xpos, ypos));
            }
            if (e.key.scancode == sf::Keyboard::Scan::Q)
            {
                this->sprite.setTexture(this->texturePunch);
                this->sprite.setPosition(sf::Vector2f(xpos, ypos));
            }
            if (this->sprite.getPosition().x < 0)
            {
                xpos = 0;
                this->sprite.setPosition(xpos, ypos);
            }
            if (this->sprite.getPosition().x >= SCREEN_WIDTH - this->width)
            {
                xpos = SCREEN_WIDTH - this->width;
                this->sprite.setPosition(xpos, ypos);
            }
        }
        if (e.type == sf::Event::KeyReleased)
        {
            if (e.key.scancode == sf::Keyboard::Scan::W)
            {
                this->sprite.setTexture(textureIdle);
                this->sprite.setPosition(xpos, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::A)
            {
                this->dx = 0;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(this->xpos + this->dx * dt, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::D)
            {
                this->dx = 0;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(xpos, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::S)
            {
                this->sprite.setTexture(textureIdle);
                this->sprite.setPosition(xpos, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::Q)
            {
                this->sprite.setTexture(textureIdle);
                this->sprite.setPosition(xpos, ypos);
            }
        }
    }
    void reset()
    {
        sf::sleep(sf::milliseconds(50));
        this->xpos = 20;
        this->sprite.setPosition(xpos, ypos);
        this->health->reset();
    }
    void draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        Player::draw(window);
    }
    bool checkCollision(const Player &other) const
    {
        return this->sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds());
    }
};
#endif