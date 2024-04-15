#include "screens/GamePlay.hpp"

void gamePlayUpdate(sf::RenderWindow &window, Character &character)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        handelCharacterEvents(character, event);
    }
    characterUpdate(window, character, event);
}

void gamePlayDraw(sf::RenderWindow &window, Character &character)
{
    characterDraw(window, character);
}