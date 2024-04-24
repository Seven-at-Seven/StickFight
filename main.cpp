#include "headers/Game.hpp"
#include "headers/Configurations.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Stick Fight 9000", sf::Style::Default);
    window.setFramerateLimit(30);

    loadGameAssets();
    while (window.isOpen())
    {

        updateGame(window);
        window.clear();
        drawGame(window);
        window.display();
    }

    return 0;
}