#include "screens/GamePlay.hpp"
#include "Globals.hpp"

void gamePlayUpdate(sf::RenderWindow &window)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void gamePlayDraw(sf::RenderWindow &window)
{
}