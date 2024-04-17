#include "components/Character.hpp"
#include <iostream>

sf::Texture CharacterTextures[3];

// Character states
short texturesLimt = 6;
short frames = 0;
bool onGround = false;
bool isMoving = false;
bool isPunshing = false;
bool onBlock = false;
bool facingLeft = false;

void loadCharacterAssets()
{
  if (!CharacterTextures[0].loadFromFile(IDLE_TEXTURE))
  {
    std::cout << "Error loading idle character assets" << std::endl;
  }
  if (!CharacterTextures[1].loadFromFile(PUNCH_TEXTURE))
  {
    std::cout << "Error loading punshing character assets" << std::endl;
  }
  if (!CharacterTextures[2].loadFromFile(MOVEING_TEXTURE))
  {
    std::cout << "Error loading moving character assets" << std::endl;
  }
}
Character initializeCharacter(float width, float height,
                              float posX, float posY, sf::Color color)
{
  Character player;

  player.sprite.setTextureRect(sf::IntRect(0, 0, width, height));
  player.sprite.setPosition(sf::Vector2f(posX, posY));
  player.sprite.setColor(color);

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
    character.selectedIndex = 1;
  }
  else if (isMoving)
  {
    texturesLimt = 9;
    character.selectedIndex = 2;
  }
  else
  {
    texturesLimt = 6;
    character.selectedIndex = 0;
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

  character.sprite.setTextureRect(sf::IntRect(64 * frames, 0,
                                              character.sprite.getGlobalBounds().width,
                                              character.sprite.getGlobalBounds().height));
  // Get textures size
  sf::Vector2u textureSize = CharacterTextures[character.selectedIndex].getSize();

  // Create an image from the textures
  sf::Image image = CharacterTextures[character.selectedIndex].copyToImage();

  // Loop through each pixel
  for (unsigned int y = 0; y < textureSize.y; ++y)
  {
    for (unsigned int x = 0; x < textureSize.x; ++x)
    {
      // Get current pixel color
      sf::Color pixelColor = image.getPixel(x, y);

      // Check if black (all color components are 0)
      if (pixelColor.r == 20 && pixelColor.g == 16 && pixelColor.b == 19)
      {
        // Change to red
        image.setPixel(x, y, sf::Color::Red);
      }
    }
  }

  // Update the textures with the modified image
  CharacterTextures[character.selectedIndex].update(image);
  character.sprite.setTexture(CharacterTextures[character.selectedIndex]);
  window.draw(character.sprite);
}
