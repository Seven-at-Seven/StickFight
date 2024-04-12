#include "screens/GamePlay.hpp"
#include "Globals.hpp"

void makeCollision(Character &character, Block &block)
{
    if (character.getShape().getGlobalBounds().intersects(block.getShape().getGlobalBounds()))
    {
        character.getShape().setPosition(character.getShape().getPosition().x, block.getShape().getPosition().y - character.getShape().getSize().y);
    }
}

void gamePlayUpdate(sf::RenderWindow &window, Character &character, Block &surface)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Character movement ====
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
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

    // Character collision ====
    makeCollision(character, surface);
    // ====

    // Character jump ====
    character.jump();
    // ====
}

void gamePlayDraw(sf::RenderWindow &window, Character &character, Block &surface)
{
    window.draw(surface.getShape());
    window.draw(character.getShape());
}