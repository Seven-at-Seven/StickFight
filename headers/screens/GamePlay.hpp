#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

struct Character
{
  sf::RectangleShape c;

  Character(float width, float height, sf::Color color, float posX, float posY)
  {
    c.setSize(sf::Vector2f(width, height));
    c.setFillColor(color);
    c.setPosition(posX, posY);
  }

  sf::RectangleShape &getShape()
  {
    return c;
  }
};

void gamePlayUpdate(sf::RenderWindow &window);
void gamePlayDraw(sf::RenderWindow &window, Character character);

#endif // GAMEPLAY_H