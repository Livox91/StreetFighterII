#include "./Game.h"
#include "./Universal.h"
#ifndef PLAYSTATE_H
#define PLAYSTATE_H
class PlayState : public sm::State
{
public:
    PlayState() {}

private:
    Game StreetFighter;
    void Update(sf::Time deltaClock, sf::Event e)
    {
        StreetFighter.Play(e);
    }
    void Draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        StreetFighter.draw(window);
    }
};
#endif