#include "./Universal.h"
#include "./Player1.h"
#include "./Player2.h"
#include "./HealthBar.h"
#include "./PlayStage.h"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Background background;
    HealthBar h1;
    HealthBar h2;
    Player1 p1;
    Player2 p2;

public:
    Game() : background(backgroundSprite, healthBarSprite),
             h1(SCREEN_WIDTH / 2 - 198, 15, 0, 17, sf::Color(100, 250, 10), 1),
             h2(SCREEN_WIDTH / 2 + 187, 15, 0, 17, sf::Color(100, 250, 10), 2),
             p1(player1Sprite, &h1), p2(player2Sprite, &h2) {}
    void Play(sf::Event e)
    {
        sf::Clock de;
        sf::Clock ds;
        if (p1.checkCollision(p2))
        {
            if (p2.sprite.getTexture() == &p2.texturePunch)
            {
                p1.health->damage();
                if (p1.health->getHealth() < 2)
                    reset();
            }
        }
        if (p2.checkCollision(p1))
        {
            if (p1.sprite.getTexture() == &p1.texturePunch)
            {
                p2.health->damage();
                if (p2.health->getHealth() < 2)
                    reset();
            }
        }
        p1.play(e, de.restart().asMicroseconds());
        p2.play(e, ds.restart().asMicroseconds());
    }
    void draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        this->background.draw(window);
        this->h1.draw(window);
        this->h2.draw(window);
        this->p1.draw(window);
        this->p2.draw(window);
    }
    void reset()
    {
        p1.reset();
        p2.reset();
    }
};

#endif