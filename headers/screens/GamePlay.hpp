#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
#include "Globals.hpp"

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

class Character
{
  sf::RectangleShape c;
  sf::Vector2f velocity;
  float jumpSpeed = 10.0f;
  float gravity = 0.5f;

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

  void checkScreenCollision(sf::RenderWindow &window)
  {
    if (c.getPosition().x < 0)
    {
      c.setPosition(0, c.getPosition().y);
    }
    else if (c.getPosition().x + c.getSize().x > window.getSize().x)
    {
      c.setPosition(window.getSize().x - c.getSize().x, c.getPosition().y);
    }

    if (c.getPosition().y < 0)
    {
      c.setPosition(c.getPosition().x, 0);
    }
    else if (c.getPosition().y + c.getSize().y > window.getSize().y)
    {
      c.setPosition(c.getPosition().x, window.getSize().y - c.getSize().y);
    }
  }

  void move(float offsetX)
  {
    c.move(offsetX, 0);
  }

  void jump()
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      velocity.y = -jumpSpeed;
    }
    else
    {
      velocity.x = 0.0f;
    }

    if (c.getPosition().y < SCREENHEIGHT)
    {
      velocity.y += gravity;
    }
    else
    {
      velocity.y = 0.0f;
    }

    c.move(velocity.x, velocity.y);
  }
};

void gamePlayUpdate(sf::RenderWindow &window, Character &character);
void gamePlayDraw(sf::RenderWindow &window, Character &character);

#endif // GAMEPLAY_H