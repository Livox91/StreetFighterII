#include "../header/Universal.h"
#include "../header/Player.h"

Player::Player() {}
Player::Player(sf::RenderWindow *renderWindow, std::string image)
{
    this->spritesheet = image;
    this->window = renderWindow;
    if (!this->textureIdle.loadFromFile(spritesheet, sf::IntRect(10, 20, 55, 110)))
    {
        std::cout << "Error";
    }
    if (!this->textureJump.loadFromFile(spritesheet, sf::IntRect(725, 35, 55, 65)))
    {
        std::cout << "Error";
    }
    if (!this->textureCrouch.loadFromFile(spritesheet, sf::IntRect(84, 732, 52, 72)))
    {
        std::cout << "Error";
    }
    if (!this->texturePunch.loadFromFile(spritesheet, sf::IntRect(915, 180, 115, 100)))
    {
        std::cout << "Error";
    }

    this->sprite.setTexture(this->texturePunch);
    this->sprite.setTexture(this->textureIdle);
    this->width = this->sprite.getGlobalBounds().width;
    this->height = this->sprite.getGlobalBounds().height;
    this->xpos = 20;
    this->ypos = SCREEN_HEIGHT - this->height - 100;
    this->sprite.setPosition(sf::Vector2f(xpos, ypos));
    this->sprite.setScale(2, 2);
}
void Player::play(float dt)
{
    sf::Event e;

    while (window->pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            window->close();
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.scancode == sf::Keyboard::Scan::D)
            {
                this->dx = 20;
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
                this->dx = -20;
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
}
void Player::draw()
{
    window->draw(this->sprite);
}