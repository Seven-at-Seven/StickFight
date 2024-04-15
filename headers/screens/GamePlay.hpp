#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
#include "Globals.hpp"

#include <iostream>
#include <string>

struct Character
{
  sf::RectangleShape c;
  float width, height, posX, posY;
  sf::Color color;

  sf::Vector2f velocity;
  float jumpSpeed = 10.0f;
  float gravity = 0.5f;

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
 };

void gamePlayUpdate(sf::RenderWindow &window, Character &character);
void gamePlayDraw(sf::RenderWindow &window, Character &character);

#endif // GAMEPLAY_H