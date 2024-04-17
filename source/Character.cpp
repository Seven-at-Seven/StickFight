#include "components/Character.hpp"

// Character states
bool punsing = false;
bool moving = false;
short texturesLimt = 6;
short state = 0;

Character initializeCharacter(float width, float height, float posX, float posY, sf::Color color)
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

    moving = true;
    texturesLimt = 9;
    VELOCITY.x = -5;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    moving = true;
    texturesLimt = 9;
    VELOCITY.x = 5;
  }
  else
    moving = false;

  // ====
  if (punsing)
  {

    texturesLimt = 10;
    character.texturePath = PUNCH_TEXTURE;
  }
  else if (moving)
  {

    texturesLimt = 9;
    character.texturePath = MOVEING_TEXTURE;
  }
  else
  {

    texturesLimt = 6;
    character.texturePath = IDLE_TEXTURE;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    punsing = true;
  else
    punsing = false;

  if (state >= texturesLimt - 1)
    state = 0;
  state++;

  // isFalling ====
  if (character.sprite.getPosition().y + character.sprite.getTextureRect().height < window.getSize().y)
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

  if (character.texture.loadFromFile(character.texturePath))
  {
    character.sprite.setTextureRect(sf::IntRect(64 * state, 0,
                                                character.sprite.getGlobalBounds().width,
                                                character.sprite.getGlobalBounds().height));
    character.sprite.setTexture(character.texture);
    window.draw(character.sprite);
  }
}
