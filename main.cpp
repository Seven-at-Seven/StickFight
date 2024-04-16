#include "headers/Game.hpp"
#include "headers/Globals.hpp"
#include <iostream>


int main()
{
<<<<<<< HEAD
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Stick Fight 9000", sf::Style::Default);
=======
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), " stick fight", sf::Style::Default);
>>>>>>> feature-mainMenu
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