#include "headers/Game.hpp"
#include "headers/Globals.hpp"
#include <iostream>

// temporary ====
#include "headers/screens/GamePlay.hpp"
// ====

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Stick Fight 9000", sf::Style::Default);
    window.setFramerateLimit(30);

    // temporary ====
    Character character(50.0f, 50.0f, sf::Color::Green, 100.0f, 100.0f);
    Block surface(SCREENWIDTH, 50.0f, sf::Color::White, 0.0f, SCREENHEIGHT);
    // ====

    while (window.isOpen())
    {

        // updateGame(window);

        // temporary ====
        gamePlayUpdate(window, character, surface);
        // ====
        window.clear();
        // drawGame(window);

        // temporary ====
        gamePlayDraw(window, character, surface);
        // ====
        window.display();
    }

    return 0;
}
