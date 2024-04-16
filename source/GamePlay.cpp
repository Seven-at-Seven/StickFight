#include "screens/GamePlay.hpp"

void gamePlayUpdate(sf::RenderWindow &window, Character &character)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        handelCharacterEvents(character, event);
        if (event.type == sf::Event::KeyReleased)
        {

            if (event.key.code == sf::Keyboard::Escape)
            {

                current_screen = last_screen;
                last_screen = 0;
            }
        }
    }
    characterUpdate(window, character, event);
}

void gamePlayDraw(sf::RenderWindow &window, Character &character)
{
    characterDraw(window, character);
}