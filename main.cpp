#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

    sf::SoundBuffer bufferW, bufferA, bufferS, bufferD, bufferQ, bufferI, bufferJ, bufferK, bufferL;
if (!bufferW.loadFromFile("landing.wav") || !bufferA.loadFromFile("landing.wav") ||
    !bufferS.loadFromFile("landing.wav") || !bufferD.loadFromFile("landing.wav") ||
    !bufferQ.loadFromFile("landing.wav") || !bufferI.loadFromFile("landing.wav") ||
    !bufferJ.loadFromFile("landing.wav") || !bufferK.loadFromFile("landing.wav") ||
    !bufferL.loadFromFile("landing.wav")) {
    // Handle error loading sound files
    return -1;
}

// Create sound objects and set their buffers
sf::Sound soundW, soundA, soundS, soundD, soundQ, soundI, soundJ, soundK, soundL;
soundW.setBuffer(bufferW);
soundA.setBuffer(bufferA);
soundS.setBuffer(bufferS);
soundD.setBuffer(bufferD);
soundQ.setBuffer(bufferQ);
soundI.setBuffer(bufferI);
soundJ.setBuffer(bufferJ);
soundK.setBuffer(bufferK);
soundL.setBuffer(bufferL);




    sf::Clock deltaClock;
    while (window->isOpen())
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            stateMachine.UpdateStates(deltaClock.restart(), e);
            if (e.type == sf::Event::KeyPressed)
            {
                 if (e.key.scancode == sf::Keyboard::Scan::W)
            {
                // Play sound when W is pressed
                soundW.play();
            }
            else if (e.key.scancode == sf::Keyboard::Scan::A)
            {
                // Play sound when A is pressed
                soundA.play();
            }
            else if (e.key.scancode == sf::Keyboard::Scan::S)
            {
                // Play sound when S is pressed
                soundS.play();
            }
            else if (e.key.scancode == sf::Keyboard::Scan::D)
            {
                // Play sound when D is pressed
                soundD.play();
            }
            else if (e.key.scancode == sf::Keyboard::Scan::Q)
            {
                // Play sound when Q is pressed
                soundQ.play();
            }
             else if (e.key.scancode == sf::Keyboard::Scan::I)
            {
                // Play sound when Q is pressed
                soundI.play();
            }
             else if (e.key.scancode == sf::Keyboard::Scan::J)
            {
                // Play sound when Q is pressed
                soundJ.play();
            }
             else if (e.key.scancode == sf::Keyboard::Scan::K)
            {
                // Play sound when Q is pressed
                soundK.play();
            }
             else if (e.key.scancode == sf::Keyboard::Scan::L)
            {
                // Play sound when Q is pressed
                soundL.play();
            }
                else if (e.key.scancode == sf::Keyboard::Scan::H)
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
// g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system  -lsfml-audio
