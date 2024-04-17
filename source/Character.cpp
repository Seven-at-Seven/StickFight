#include "components/Character.hpp"
#include <iostream>

// Character states
short texturesLimt = 6;
short frames = 0;
bool onGround = false;
bool isMoving = false;
bool isPunshing = false;
bool onBlock = false;
bool facingLeft = false;

Character
initializeCharacter(float width, float height, float posX, float posY, sf::Color color)
{
  Character player;

  player.sprite.setTextureRect(sf::IntRect(0, 0, width, height));
  player.sprite.setPosition(sf::Vector2f(posX, posY));
  player.sprite.setColor(color);
  player.texturePath = IDLE_TEXTURE;

  return player;
}

void checkScreenCollision(Character &player, sf::RenderWindow &window)
{
  if (player.sprite.getPosition().x < 0)
  {
    player.sprite.setPosition(0, player.sprite.getPosition().y);
  }
  else if (player.sprite.getPosition().x + player.sprite.getTextureRect().width > window.getSize().x)
  {
    player.sprite.setPosition(window.getSize().x - player.sprite.getTextureRect().width, player.sprite.getPosition().y);
  }

  if (player.sprite.getPosition().y < 0)
  {
    player.sprite.setPosition(player.sprite.getPosition().x, 0);
  }
  else if (player.sprite.getPosition().y + player.sprite.getTextureRect().height > window.getSize().y)
  {
    player.sprite.setPosition(player.sprite.getPosition().x, window.getSize().y - player.sprite.getTextureRect().height);
  }
}

void move(Character &player, sf::Vector2f offset)
{
  player.sprite.move(offset);
}

void handelCharacterEvents(Character &character, sf::Event &event)
{

  // Handle Key pressed
  if (event.type == sf::Event::KeyPressed)
  {

    switch (event.key.code)
    {
    case sf::Keyboard::Left:
    {

      VELOCITY.x = -5;
      isMoving = true;
      if (!facingLeft)
      {
        facingLeft = !facingLeft;
        character.sprite.setScale(sf::Vector2f(-1.f, 1.f));
        character.sprite.setPosition(character.sprite.getPosition().x + 64,
                                     character.sprite.getPosition().y);
      }
    }
    break;
    case sf::Keyboard::Right:
    {

      VELOCITY.x = 5;
      isMoving = true;
      if (facingLeft)
      {
        facingLeft = !facingLeft;
        character.sprite.setScale(sf::Vector2f(1.f, 1.f));
        character.sprite.setPosition(character.sprite.getPosition().x - 64,
                                     character.sprite.getPosition().y);
      }
    }
    break;
    case sf::Keyboard::Up:
    {

      if (onGround)
      {
        onBlock = false;
        onGround = false;
        VELOCITY.y = JUMP;
      }
      break;
    }
    case sf::Keyboard::Numpad0:
    {
      isPunshing = true;
      break;
    }
    default:
      break;
    }
  }

  // Handle Key Released
  if (event.type == sf::Event::KeyReleased)
  {
    switch (event.key.code)
    {
    case sf::Keyboard::Left:

    case sf::Keyboard::Right:
      isMoving = false;
      VELOCITY.x = 0;
      break;

    case sf::Keyboard::Numpad0:
      isPunshing = false;
    default:
      break;
    }
  }
}

void characterUpdate(sf::RenderWindow &window, Character &character,
                     Map &map)
{

  checkScreenCollision(character, window);
  move(character, VELOCITY);

  if (isPunshing)
  {
    texturesLimt = 10;
    character.texturePath = (char *)PUNCH_TEXTURE;
  }
  else if (isMoving)
  {
    texturesLimt = 9;
    character.texturePath = (char *)MOVEING_TEXTURE;
  }
  else
  {
    texturesLimt = 6;
    character.texturePath = (char *)IDLE_TEXTURE;
  }

  frames++;
  if (frames >= texturesLimt - 1)
    frames = 0;

  // isFalling
  if (character.sprite.getPosition().y + character.sprite.getTextureRect().height < SCREENHEIGHT && !onBlock)
  {
    onGround = false;
    VELOCITY.y += GRAVITY.y;
  }
  else
  {
    onGround = true;
    VELOCITY.y = 0;
  }
}

void characterDraw(sf::RenderWindow &window, Character &character)
{

  if (character.texture.loadFromFile(character.texturePath))
  {
    character.sprite.setTextureRect(sf::IntRect(64 * frames, 0,
                                                character.sprite.getGlobalBounds().width,
                                                character.sprite.getGlobalBounds().height));

    character.sprite.setTexture(character.texture);
  }
  window.draw(character.sprite);
}
