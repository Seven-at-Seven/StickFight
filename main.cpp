#include "headers/Game.hpp"
#include "headers/Globals.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), " stick fight", sf::Style::Default);
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
