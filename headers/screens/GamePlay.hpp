#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

class Character
{
  sf::RectangleShape c;
  sf::Vector2f velocity;
  float jumpSpeed = 10.0f;
  float gravity = 0.5f;
  float groundHeight = 500.0f; // Adjust this to match your ground level

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

    if (c.getPosition().y < groundHeight || velocity.y < 0.0f)
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