#include "screens/GamePlay.hpp"
#include "Globals.hpp"
#include <iostream>

void gamePlayUpdate(sf::RenderWindow &window, Character &character)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Character movement ====
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        std::cout << "Left key pressed" << std::endl;
        character.move(-5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        character.move(5);
    }
    // ====

    // Character gravity ====
    if (character.getShape().getPosition().y < window.getSize().y - 100)
    {
        character.getShape().move(0, 5);
    }
    // ====
}

void gamePlayDraw(sf::RenderWindow &window, Character &character)
{
    
    window.draw(character.getShape());
}