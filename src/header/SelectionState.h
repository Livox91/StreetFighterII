#include "./Universal.h"
#include "./SelectionScreen.h"

#ifndef SELECTIONSTATE_H
#define SELECTIONSTATE_H

class SelectionState : public sm::State
{

public:
    SelectionState() : screen(selectionScreenSprite) {}

private:
    SelectionScreen screen;
    void Update(sf::Time deltaTime, sf::Event e)
    {
    }
    void Draw(const std::shared_ptr<sf::RenderWindow> &window)
    {
        this->screen.draw(window);
    }
};

#endif