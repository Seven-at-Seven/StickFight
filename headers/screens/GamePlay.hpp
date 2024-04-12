#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

class Character
{
  sf::RectangleShape c;

public:
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

  void move(float offsetX)
  {
    c.move(offsetX, 0);
  }
};

class Block
{
  sf::RectangleShape b;

public:
  Block(float width, float height, sf::Color color, float posX, float posY)
  {
    b.setSize(sf::Vector2f(width, height));
    b.setFillColor(color);
    b.setPosition(posX, posY);
  }

  sf::RectangleShape &getShape()
  {
    return b;
  }
};

void gamePlayUpdate(sf::RenderWindow &window, Character &character, Block &surface);
void gamePlayDraw(sf::RenderWindow &window, Character &character, Block &surface);

#endif // GAMEPLAY_H