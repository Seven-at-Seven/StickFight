#include "components/Character.hpp"
#include "Globals.hpp"
#include <iostream>

// Textures
sf::Texture CharacterTextures[MAX_PLAYERS_NUMBER][4];

// damage struct
struct Damage
{
  bool yes;
  int damageQuantity;
};

// Character states
short texturesLimt[MAX_PLAYERS_NUMBER] = {6};
short frames[MAX_PLAYERS_NUMBER] = {0};
bool onGround[MAX_PLAYERS_NUMBER] = {false};
bool isMoving[MAX_PLAYERS_NUMBER] = {false};
bool isPunshing[MAX_PLAYERS_NUMBER] = {false};
bool isOnBlock[MAX_PLAYERS_NUMBER] = {false};
bool isFacingLeft[MAX_PLAYERS_NUMBER] = {false};
bool isHavingGun[MAX_PLAYERS_NUMBER] = {false};
bool isFlying[MAX_PLAYERS_NUMBER] = {false};
Damage isDamaged[MAX_PLAYERS_NUMBER] = {};
sf::Vector2f playerVelocity[MAX_PLAYERS_NUMBER] = {};

// Characters
Character charactersArray[MAX_PLAYERS_NUMBER];

void loadCharacterAssets()
{

  for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
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

      if (!isFlying[0])
        playerVelocity[0].x = -5;
      isMoving[0] = true;
      if (!isFacingLeft[0])
      {
        isFacingLeft[0] = !isFacingLeft[0];
        charactersArray[0].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[0].sprite.setOrigin(sf::Vector2f(charactersArray[0].sprite.getGlobalBounds().width,
                                                         0));
      }
      break;
    }
    case sf::Keyboard::D:
    {

      if (!isFlying[0])
        playerVelocity[0].x = 5;
      isMoving[0] = true;
      if (isFacingLeft[0])
      {
        isFacingLeft[0] = !isFacingLeft[0];
        charactersArray[0].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[0].sprite.setOrigin(sf::Vector2f(0, 0));
      }
      break;
    }
    case sf::Keyboard::W:
    {

      if (onGround[0] || isOnBlock[0])
      {

        isOnBlock[0] = false;
        onGround[0] = false;
        playerVelocity[0].y = JUMP;
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

      if (!isFlying[1])
        playerVelocity[1].x = -5;
      isMoving[1] = true;
      if (!isFacingLeft[1])
      {
        isFacingLeft[1] = !isFacingLeft[1];
        charactersArray[1].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[1].sprite.setOrigin(sf::Vector2f(charactersArray[1].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::K:
    {

      if (!isFlying[1])
        playerVelocity[1].x = 5;
      isMoving[1] = true;
      if (isFacingLeft[1])
      {
        isFacingLeft[1] = !isFacingLeft[1];
        charactersArray[1].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[1].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::U:
    {

      if (onGround[1] || isOnBlock[1])
      {
        isOnBlock[1] = false;
        onGround[1] = false;
        playerVelocity[1].y = JUMP;
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

      if (!isFlying[2])
        playerVelocity[2].x = -5;
      isMoving[2] = true;
      if (!isFacingLeft[2])
      {
        isFacingLeft[2] = !isFacingLeft[2];
        charactersArray[2].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(charactersArray[2].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::Right:
    {

      if (!isFlying[2])
        playerVelocity[2].x = 5;
      isMoving[2] = true;
      if (isFacingLeft[2])
      {
        isFacingLeft[2] = !isFacingLeft[2];
        charactersArray[2].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::Up:
    {

      if (onGround[2] || isOnBlock[2])
      {
        isOnBlock[2] = false;
        onGround[2] = false;
        playerVelocity[2].y = JUMP;
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

      if (!isFlying[3])
        playerVelocity[3].x = -5;
      isMoving[3] = true;
      if (!isFacingLeft[3])
      {
        isFacingLeft[3] = !isFacingLeft[3];
        charactersArray[3].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[3].sprite.setOrigin(sf::Vector2f(charactersArray[3].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::Numpad6:
    {

      if (!isFlying[3])
        playerVelocity[3].x = 5;
      isMoving[3] = true;
      if (isFacingLeft[3])
      {
        isFacingLeft[3] = !isFacingLeft[3];
        charactersArray[3].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::Numpad8:
    {

      if (onGround[0] || isOnBlock[0])
      {
        isOnBlock[3] = false;
        onGround[3] = false;
        playerVelocity[3].y = JUMP;
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
      playerVelocity[0].x = 0;
      break;
    case sf::Keyboard::E:
      isPunshing[0] = false;
      break;
    // Player 1
    case sf::Keyboard::K:
    case sf::Keyboard::H:
      isMoving[1] = false;
      playerVelocity[1].x = 0;
      break;
    case sf::Keyboard::I:
      isPunshing[1] = false;
      break;
    // Player 2
    case sf::Keyboard::Left:
    case sf::Keyboard::Right:
      isMoving[2] = false;
      playerVelocity[2].x = 0;
      break;
    case sf::Keyboard::Numpad0:
      isPunshing[2] = false;
      break;

    // Player 3
    case sf::Keyboard::Numpad4:
    case sf::Keyboard::Numpad6:
      isMoving[3] = false;
      playerVelocity[3].x = 0;
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

  for (int i = 0; i < map[current_map].num_of_blocks; i++)
  {
    auto blockBounds = map[current_map].blocks[i].block_area.getGlobalBounds();

    if (blockBounds.intersects(playerBounds) && !isOnBlock[i])
    {
      // Collision from top
      if (playerPosition.y < blockBounds.top)
      {
        player.area.setPosition(sf::Vector2f(playerPosition.x, blockBounds.top - playerBounds.height));
        isOnBlock[playerIndex] = true;
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
      isOnBlock[playerIndex] = false;
    }
  }
}

void checkPlayerHitCollision(Character &player, int playerIndex)
{
  auto playerBounds = player.sprite.getGlobalBounds();
  for (int i = 0; i < number_of_players; i++)
  {
    if (i == playerIndex)
      continue;
    auto otherPlayerBounds = charactersArray[i].sprite.getGlobalBounds();
    if (playerBounds.intersects(otherPlayerBounds))
    {
      if (isPunshing[playerIndex] && !isFlying[playerIndex])
      {

        playerVelocity[i].x = isFacingLeft[playerIndex] ? -20 : 20;
        playerVelocity[i].y = JUMP / 4;
        isFlying[i] = true;
        onGround[i] = false;
        isDamaged[i].yes = true;
        isDamaged[i].damageQuantity = 3;
      }
    }
  }
}

void charactersUpdate(sf::RenderWindow &window)
{

  for (int i = 0; i < number_of_players; i++)
  {
    move(charactersArray[i], playerVelocity[i]);
    // Collision Checks
    checkScreenCollision(charactersArray[i], i);
    checkBlockCollision(charactersArray[i], i);
    checkPlayerHitCollision(charactersArray[i], i);

    if (isFacingLeft[i])
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

    if (isOnBlock[i] || onGround[i])
    {
      playerVelocity[i].y = 0;
    }
    else
    {
      playerVelocity[i].y += GRAVITY.y;
    }
    if (isFlying[i])
    {
      if (playerVelocity[i].x > 0)
      {
        playerVelocity[i].x -= 2;
      }
      else if (playerVelocity[i].x < 0)
      {
        playerVelocity[i].x += 2;
      }
      else
        isFlying[i] = false;
    }

    // Handle hit
    if (isDamaged[i].yes && healthBarArray[i].currentHP > 0)
    {
      healthBarArray[i].currentHP = healthBarArray[i].currentHP -
                                    isDamaged[i].damageQuantity;
      isDamaged[i].yes = false;
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
