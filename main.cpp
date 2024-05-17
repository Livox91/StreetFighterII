#include "./src/header/Universal.h"
#include "./src/StateMachine.cpp"
#include "./src/header/PlayState.h"
#include "./src/header/SelectionState.h"

int main()
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Street Fighter II ");

    std::shared_ptr<PlayState> playState = std::make_shared<PlayState>();
    std::shared_ptr<SelectionState> selectionState = std::make_shared<SelectionState>();
    sm::StateMachine stateMachine(selectionState);

    sf::Clock deltaClock;
    while (window->isOpen())
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            stateMachine.UpdateStates(deltaClock.restart(), e);
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.scancode == sf::Keyboard::Scan::H)
                {
                    selectionState->SetVisible(false);
                    stateMachine.AddState(playState);
                }
            }
        }
        window->clear();
        stateMachine.DrawStates(window);
        window->display();
        sf::sleep(sf::milliseconds(5));
    }

    stateMachine.ClearAll();
    window->close();
    return 0;
}
// g++ -Isrc/include -c main.cpp
// g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
