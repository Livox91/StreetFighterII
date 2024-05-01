#include "./src/header/Universal.h"
#include "./src/header/Game.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Street Fighter II ");
    Game StreetFighter(&window);
    while (window.isOpen())
    {
        StreetFighter.Play();
    }
    return 0;
}

// g++ -Isrc/include -c main.cpp
// g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
