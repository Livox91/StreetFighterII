#include "./Universal.h"
#include "./Player.h"

#ifndef PLAYER2_H
#define PLAYER2_H

class Player2 : public Player
{
public:
    Player2(sf::RenderWindow *renderWindow, std::string image, HealthBar *health) : Player(renderWindow, image)
    {
        if (!this->textureIdle.loadFromFile(spritesheet, sf::IntRect(511, 9, 65, 105)))
        {
            std::cout << "Error";
        }
        if (!this->textureJump.loadFromFile(spritesheet, sf::IntRect(365, 585, 70, 80)))
        {
            std::cout << "Error";
        }
        if (!this->textureCrouch.loadFromFile(spritesheet, sf::IntRect(845, 755, 70, 75)))
        {
            std::cout << "Error";
        }
        if (!this->texturePunch.loadFromFile(spritesheet, sf::IntRect(920, 290, 110, 100)))
        {
            std::cout << "Error";
        }

        this->sprite.setTexture(this->texturePunch);
        this->sprite.setTexture(this->textureIdle);
        this->width = this->sprite.getGlobalBounds().width;
        this->height = this->sprite.getGlobalBounds().height;
        this->xpos = SCREEN_WIDTH - this->width * 2;
        this->ypos = SCREEN_HEIGHT - this->height * 2;
        this->sprite.setPosition(sf::Vector2f(xpos, ypos));
        this->sprite.setScale(2, 2);
        this->health = health;
    }
    void play(sf::Event e, float dt) override
    {
        if (e.type == sf::Event::Closed)
            window->close();
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.scancode == sf::Keyboard::Scan::L)
            {
                this->dx = 5;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(sf::Vector2f(xpos, ypos));
            }
            if (e.key.scancode == sf::Keyboard::Scan::I)
            {
                this->sprite.setTexture(this->textureJump);
                this->sprite.setPosition(sf::Vector2f(xpos + 50, ypos));
                this->health->damage();
            }
            if (e.key.scancode == sf::Keyboard::Scan::K)
            {
                this->sprite.setTexture(this->textureCrouch);
                this->sprite.setPosition(sf::Vector2f(xpos, ypos + (this->height - 50)));
            }
            if (e.key.scancode == sf::Keyboard::Scan::J)
            {
                this->dx = -5;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(sf::Vector2f(xpos, ypos));
            }
            if (e.key.scancode == sf::Keyboard::Scan::Comma)
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
            if (e.key.scancode == sf::Keyboard::Scan::I)
            {
                this->sprite.setTexture(textureIdle);
                this->sprite.setPosition(xpos, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::J)
            {
                this->dx = 0;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(this->xpos + this->dx * dt, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::L)
            {
                this->dx = 0;
                this->xpos = this->xpos + this->dx * dt;
                this->sprite.setPosition(xpos, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::K)
            {
                this->sprite.setTexture(textureIdle);
                this->sprite.setPosition(xpos, ypos);
            }
            if (e.key.scancode == sf::Keyboard::Scan::Comma)
            {
                this->sprite.setTexture(textureIdle);
                this->sprite.setPosition(xpos, ypos);
            }
        }
    }
    void draw()
    {
        Player::draw();
    }
    bool checkCollision(const Player &other) const
    {
        return this->sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds());
    }
};
#endif