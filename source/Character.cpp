#include "components/Character.hpp"

Character initializeCharacter(float width, float height, float posX, float posY, sf::Color color)
{
  Character player;

  player.rect.setSize(sf::Vector2f(width, height));
  player.rect.setPosition(sf::Vector2f(posX, posY));
  player.rect.setFillColor(color);

  return player;
}

void checkScreenCollision(Character &player, sf::RenderWindow &window)
{
  if (player.rect.getPosition().x < 0)
  {
    player.rect.setPosition(0, player.rect.getPosition().y);
  }
  else if (player.rect.getPosition().x + player.rect.getSize().x > window.getSize().x)
  {
    player.rect.setPosition(window.getSize().x - player.rect.getSize().x, player.rect.getPosition().y);
  }

  if (player.rect.getPosition().y < 0)
  {
    player.rect.setPosition(player.rect.getPosition().x, 0);
  }
  else if (player.rect.getPosition().y + player.rect.getSize().y > window.getSize().y)
  {
    player.rect.setPosition(player.rect.getPosition().x, window.getSize().y - player.rect.getSize().y);
  }
}

void move(Character &player, sf::Vector2f offset)
{
  player.rect.move(offset);
}

void handelCharacterEvents(Character &character, sf::Event &event)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
    {
      VELOCITY.x = 0;
    }
  }
}

void characterUpdate(sf::RenderWindow &window, Character &character, sf::Event &event)
{
  bool isFalling = true;

  move(character, VELOCITY);

  // Character movement ====
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    VELOCITY.x = -5;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    VELOCITY.x = 5;
  }
  // ====

  // isFalling ====
  if (character.rect.getPosition().y + character.rect.getSize().y < window.getSize().y)
  {
    isFalling = true;
  }
  else
  {
    isFalling = false;
    VELOCITY.y = 0;
  }
  // ====

  // Character gravity ====
  if (isFalling)
  {
    VELOCITY.y += GRAVITY.y;
  }
  // ====

  // Character jump ====
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isFalling)
  {
    VELOCITY.y = JUMP;
  }
  // ====

  // Character screen collision ====
  checkScreenCollision(character, window);
  // ====
}

void characterDraw(sf::RenderWindow &window, Character &character)
{
  window.draw(character.rect);
}
