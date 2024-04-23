#include "components/Character.hpp"
#include <iostream>

sf::Texture CharacterTextures[4][4];

// Character states
short texturesLimt[4] = {6};
short frames[4] = {0};
bool onGround[4] = {false};
bool isMoving[4] = {false};
bool isPunshing[4] = {false};
bool onBlock[4] = {false};
bool facingLeft[4] = {false};
bool isHavingGun[4] = {false};
Character charactersArray[4];

void loadCharacterAssets()
{

  for (int i = 0; i < 4; i++)
  {

    if (!CharacterTextures[i][0].loadFromFile(IDLE_TEXTURE))
    {
      std::cout << "Error loading idle character assets" << std::endl;
    }
    if (!CharacterTextures[i][1].loadFromFile(PUNCH_TEXTURE))
    {
      std::cout << "Error loading punshing character assets" << std::endl;
    }
    if (!CharacterTextures[i][2].loadFromFile(MOVEING_TEXTURE))
    {
      std::cout << "Error loading moving character assets" << std::endl;
    }
    if (!CharacterTextures[i][3].loadFromFile(HAVING_GUN_TEXTURE))
    {
      std::cout << "Error loading idle character assets" << std::endl;
    }
    charactersArray[i].sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    charactersArray[i].area.setPosition(sf::Vector2f(200 * i + 20, 100));
    charactersArray[i].area.setSize(sf::Vector2f(40, 64));
    charactersArray[i].color = palyersColors[i];
    charactersArray[i].area.setFillColor(sf::Color::Red);
    for (int j = 0; j < 4; j++)
    {

      // Get textures size
      sf::Vector2u textureSize = CharacterTextures[i][j].getSize();

      // Create an image from the textures
      sf::Image image = CharacterTextures[i][j].copyToImage();

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
            image.setPixel(x, y, charactersArray[i].color);
          }
        }
      }
      CharacterTextures[i][j].update(image);
    }
  }
}

void checkScreenCollision(Character &player, int playerIndex)
{
  if (player.area.getPosition().x <= 0)
  {
    player.area.setPosition(0, player.area.getPosition().y);
  }
  else if (player.area.getPosition().x + player.area.getSize().x > SCREENWIDTH)
  {
    player.area.setPosition(SCREENWIDTH - player.area.getSize().x, player.area.getPosition().y);
  }

  if (player.area.getPosition().y <= 0)
  {
    player.area.setPosition(player.area.getPosition().x, 0);
  }
  else if (player.area.getPosition().y + player.area.getSize().y >= SCREENHEIGHT)
  {
    onGround[playerIndex] = true;
    player.area.setPosition(player.area.getPosition().x, SCREENHEIGHT - player.area.getSize().y);
  }
}

void move(Character &player, sf::Vector2f offset)
{
  player.area.move(offset);
}

void handelCharacterEvents(sf::Event &event)
{

  // Handle Key pressed
  if (event.type == sf::Event::KeyPressed)
  {

    switch (event.key.code)
    {
      // Player 0
    case sf::Keyboard::A:
    {

      VELOCITY[0].x = -5;
      isMoving[0] = true;
      if (!facingLeft[0])
      {
        facingLeft[0] = !facingLeft[0];
        charactersArray[0].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[0].sprite.setOrigin(sf::Vector2f(charactersArray[0].sprite.getGlobalBounds().width,
                                                         0));
      }
      break;
    }
    case sf::Keyboard::D:
    {

      VELOCITY[0].x = 5;
      isMoving[0] = true;
      if (facingLeft[0])
      {
        facingLeft[0] = !facingLeft[0];
        charactersArray[0].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[0].sprite.setOrigin(sf::Vector2f(0, 0));
      }
      break;
    }
    case sf::Keyboard::W:
    {

      if (onGround[0] || onBlock[0])
      {

        onBlock[0] = false;
        onGround[0] = false;
        VELOCITY[0].y = JUMP;
      }
      break;
    }
    case sf::Keyboard::E:
    {
      isPunshing[0] = true;
      break;
    }
      // Player 1
    case sf::Keyboard::H:
    {

      VELOCITY[1].x = -5;
      isMoving[1] = true;
      if (!facingLeft[1])
      {
        facingLeft[1] = !facingLeft[1];
        charactersArray[1].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[1].sprite.setOrigin(sf::Vector2f(charactersArray[1].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::K:
    {

      VELOCITY[1].x = 5;
      isMoving[1] = true;
      if (facingLeft[1])
      {
        facingLeft[1] = !facingLeft[1];
        charactersArray[1].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[1].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::U:
    {

      if (onGround[1] || onBlock[1])
      {
        onBlock[1] = false;
        onGround[1] = false;
        VELOCITY[1].y = JUMP;
      }
      break;
    }
    case sf::Keyboard::I:
    {
      isPunshing[1] = true;
      break;
    }

      // Player 2
    case sf::Keyboard::Left:
    {

      VELOCITY[2].x = -5;
      isMoving[2] = true;
      if (!facingLeft[2])
      {
        facingLeft[2] = !facingLeft[2];
        charactersArray[2].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(charactersArray[2].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::Right:
    {

      VELOCITY[2].x = 5;
      isMoving[2] = true;
      if (facingLeft[2])
      {
        facingLeft[2] = !facingLeft[2];
        charactersArray[2].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::Up:
    {

      if (onGround[2] || onBlock[2])
      {
        onBlock[2] = false;
        onGround[2] = false;
        VELOCITY[2].y = JUMP;
      }
      break;
    }
    case sf::Keyboard::Numpad0:
    {
      isPunshing[2] = true;
      break;
    }
      // Player 3
    case sf::Keyboard::Numpad4:
    {

      VELOCITY[3].x = -5;
      isMoving[3] = true;
      if (!facingLeft[3])
      {
        facingLeft[3] = !facingLeft[3];
        charactersArray[3].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[3].sprite.setOrigin(sf::Vector2f(charactersArray[3].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::Numpad6:
    {

      VELOCITY[3].x = 5;
      isMoving[3] = true;
      if (facingLeft[3])
      {
        facingLeft[3] = !facingLeft[3];
        charactersArray[3].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::Numpad8:
    {

      if (onGround[0] || onBlock[0])
      {
        onBlock[3] = false;
        onGround[3] = false;
        VELOCITY[3].y = JUMP;
      }
      break;
    }
    case sf::Keyboard::Numpad9:
    {
      isPunshing[3] = true;
      break;
    }

    default:
      break;
    }

    // Handle Key Released
  }
  if (event.type == sf::Event::KeyReleased)
  {

    switch (event.key.code)
    {

    // Player 0
    case sf::Keyboard::A:
    case sf::Keyboard::D:
      isMoving[0] = false;
      VELOCITY[0].x = 0;
      break;
    case sf::Keyboard::E:
      isPunshing[0] = false;
      break;
    // Player 1
    case sf::Keyboard::K:
    case sf::Keyboard::H:
      isMoving[1] = false;
      VELOCITY[1].x = 0;
      break;
    case sf::Keyboard::I:
      isPunshing[1] = false;
      break;
    // Player 2
    case sf::Keyboard::Left:
    case sf::Keyboard::Right:
      isMoving[2] = false;
      VELOCITY[2].x = 0;
      break;
    case sf::Keyboard::Numpad0:
      isPunshing[2] = false;
      break;

    // Player 3
    case sf::Keyboard::Numpad4:
    case sf::Keyboard::Numpad6:
      isMoving[3] = false;
      VELOCITY[3].x = 0;
      break;
    case sf::Keyboard::Numpad9:
      isPunshing[3] = false;
      break;
    default:
      break;
    }
  }
}

void checkBlockCollision(Character &player, int playerIndex)
{

  sf::Vector2f playerPosition = player.area.getPosition();
  auto playerBounds = player.area.getGlobalBounds();

  for (int i = 0; i < map[curmap].num_of_blocks; i++)
  {
    auto blockBounds = map[curmap].blocks[i].block_area.getGlobalBounds();

    if (blockBounds.intersects(playerBounds) && !onBlock[i])
    {
      // Collision from top
      if (playerPosition.y < blockBounds.top)
      {
        player.area.setPosition(sf::Vector2f(playerPosition.x, blockBounds.top - playerBounds.height));
        onBlock[playerIndex] = true;
        break;
      }
      // Collision from Right
      else if (playerBounds.left + playerBounds.width > blockBounds.left + blockBounds.width)
      {

        player.area.setPosition(sf::Vector2f(blockBounds.left + blockBounds.width, playerBounds.top));
      }
      // Collision from Left
      else if (playerBounds.left < blockBounds.left)
      {

        player.area.setPosition(sf::Vector2f(blockBounds.left - playerBounds.width, playerBounds.top));
      }
      // Collision from Bottom
      else if (playerBounds.top + playerBounds.height > blockBounds.top + blockBounds.height)
      {

        player.area.setPosition(sf::Vector2f(playerPosition.x, blockBounds.top + blockBounds.height + 3));
      }
    }
    else
    {
      onBlock[playerIndex] = false;
    }
  }
}
void charactersUpdate(sf::RenderWindow &window)
{

  for (int i = 0; i < number_of_players; i++)
  {
    move(charactersArray[i], VELOCITY[i]);
    checkScreenCollision(charactersArray[i], i);
    checkBlockCollision(charactersArray[i], i);
    if (facingLeft[i])
      charactersArray[i].sprite.setPosition(charactersArray[i].area.getPosition() + sf::Vector2f(-18, 0));
    else
      charactersArray[i].sprite.setPosition(charactersArray[i].area.getPosition() + sf::Vector2f(-10, 0));

    if (isHavingGun[i])
    {
      texturesLimt[i] = 0;
      charactersArray[i].selectedIndex = 3;
    }
    else if (isPunshing[i])
    {
      texturesLimt[i] = 10;
      charactersArray[i].selectedIndex = 1;
    }
    else if (isMoving[i])
    {
      texturesLimt[i] = 9;
      charactersArray[i].selectedIndex = 2;
    }
    else
    {
      texturesLimt[i] = 6;
      charactersArray[i].selectedIndex = 0;
    }

    frames[i]++;
    if (frames[i] >= texturesLimt[i] - 1)
      frames[i] = 0;

    if (onBlock[i] || onGround[i])
    {
      VELOCITY[i].y = 0;
    }
    else
    {
      VELOCITY[i].y += GRAVITY.y;
    }
  }
}
void charactersDraw(sf::RenderWindow &window)
{
  for (int i = 0; i < number_of_players; i++)
  {
    charactersArray[i].sprite.setTextureRect(sf::IntRect(64 * frames[i], 0,
                                                         charactersArray[i].sprite.getGlobalBounds().width,
                                                         charactersArray[i].sprite.getLocalBounds().height));
    charactersArray[i].sprite.setTexture(CharacterTextures[i][charactersArray[i].selectedIndex]);

    window.draw(charactersArray[i].sprite);
  }
}
