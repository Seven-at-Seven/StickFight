#include "headers/Game.hpp"
#include "headers/Globals.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Snake Game", sf::Style::Default);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        updateGame(window);
        window.clear();
        drawGame(window);
        window.display();
    }

    return 0;
}
