#include "./Universal.h"
#include "./Player1.h"
#include "./Player2.h"
#include "./Background.h"
#include "./HealthBar.h"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    sf::RenderWindow *renderWindow;
    Background background;
    HealthBar h1;
    HealthBar h2;
    Player1 p1 ;
    Player2 p2 ;

public:
    Game(sf::RenderWindow *window) : renderWindow(window),
                                     background(window, backgroundSprite, healthBarSprite),
                                     h1(window, SCREEN_WIDTH / 2 - 198, 15, 183, 17, sf::Color(100, 250, 10), 1),
                                     h2(window, SCREEN_WIDTH / 2 + 187, 15, 0, 17, sf::Color(100, 250, 10), 2),
                                     p1(window, player1Sprite, &h1), p2(window, player2Sprite, &h2) {}
    void Play()
    {
        sf::Event e;
        while (renderWindow->pollEvent(e))
        {
            sf::Clock de;
            sf::Clock ds;
            if (p1.checkCollision(p2))
            {
                if (p2.sprite.getTexture() == &p2.texturePunch)
                {
                    p1.health->damage();
                }
            }
            if (p2.checkCollision(p1))
            {
                if (p1.sprite.getTexture() == &p1.texturePunch)
                {
                    p2.health->damage();
                }
            }
            p1.play(e, de.restart().asMicroseconds());
            p2.play(e, ds.restart().asMicroseconds());
        }
        draw();
    }
    void draw()
    {
        this->renderWindow->clear();
        this->background.draw();
        this->h1.draw();
        this->h2.draw();
        this->p1.draw();
        this->p2.draw();
        this->renderWindow->display();
    }
};

#endif