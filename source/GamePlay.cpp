#include "screens/GamePlay.hpp"
#include "Globals.hpp"

void gamePlayUpdate(sf::RenderWindow &window, Character &character)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Character movement ====
    character.movement();
    // ====

    // Character gravity ====

    // ====

    // Character jump ====

    // ====

    // Character screen collision ====
    character.checkScreenCollision(window);
    // ====
}

void gamePlayDraw(sf::RenderWindow &window, Character &character)
{
    window.draw(character.getShape());
}