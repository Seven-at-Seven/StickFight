#include "headers/Game.hpp"
#include "headers/Globals.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Snake Game", sf::Style::Default);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {

        updateGame(window);
        window.clear();
        drawGame(window);
        window.display();
    }

    return 0;
}