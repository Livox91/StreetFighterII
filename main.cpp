#include "./src/header/Universal.h"
#include "./src/cpp/Player.cpp"
#include "./src/cpp/Background.cpp"

int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
    Player p1(&window, "./src/assests/images/Ken.png");
    Background b0(&window, "./src/assests/images/background.png");
    sf::Clock dt;
    while (window.isOpen())
    {
        sf::Event event;
        p1.play(dt.restart().asMilliseconds());
        // while (window.pollEvent(event))
        // {
        //     p1.play(&event);
        //     if (event.type == sf::Event::Closed)
        //         window.close();
        // }
        window.clear();
        b0.draw();
        p1.draw();
        window.display();
    }

    return 0;
}

// g++ -Isrc/include -c main.cpp
// g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
