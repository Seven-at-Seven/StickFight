#include "screens/GamePlay.hpp"
#include "Globals.hpp"

void gamePlayUpdate(sf::RenderWindow &window)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyReleased)
        {

            if (event.key.code == sf::Keyboard::Escape)
            {

                current_screen = last_screen;
                last_screen = 0;
            }
        }
    }
}

void gamePlayDraw(sf::RenderWindow &window)
{
}