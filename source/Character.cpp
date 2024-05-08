#include "components/Character.hpp"
#include "Globals.hpp"
#include "Configurations.hpp"
#include <iostream>
#include "SFML/Audio.hpp"

// Textures
sf::Texture CharacterTextures[MAX_PLAYERS_NUMBER][4];

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
    charactersArray[i].area.setSize(sf::Vector2f(40, 64));
    charactersArray[i].color = palyersColors[i];
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

void updateCharacters()
{

  for (int i = 0; i < number_of_players; i++)
  {
    if (charactersArray[i].isDead)
      continue;

    move(charactersArray[i]);

    if (checkPlayerHitCollision(charactersArray[i]))
      handlePlayerHitted(charactersArray[i], i);

    if (charactersArray[i].isDamaged)
    {

      charactersArray[i].isDamaged = false;
      if (healthBarArray[i].currentHP > 0)
      {
        healthBarArray[i].currentHP -= charactersArray[i].damageQuantity;
      }
    }

    checkScreenCollision(charactersArray[i]);

    checkBlockCollision(charactersArray[i]);

    updatePlayerAnimation(charactersArray[i]);
  }
}

void drawCharacters(sf::RenderWindow &window)
{
  for (int i = 0; i < number_of_players; i++)
  {
    if (charactersArray[i].isDead)
      continue;
    charactersArray[i].sprite.setTextureRect(sf::IntRect(64 * charactersArray[i].frames, 0,
                                                         charactersArray[i].sprite.getGlobalBounds().width,
                                                         charactersArray[i].sprite.getLocalBounds().height));
    charactersArray[i].sprite.setTexture(CharacterTextures[i][charactersArray[i].selectedIndex]);

    window.draw(charactersArray[i].sprite);
  }
}

void spawnCharacters()
{
  for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
  {
    charactersArray[i].isDead = false;
    charactersArray[i].isHavingGun = false;
    healthBarArray[i].currentHP = 100;
    charactersArray[i].playerVelocity = {};
  }

  if (current_map == 0)
  {
    int characterXposition0 = std::rand() % (int)1040 + 110;
    int characterXposition1 = std::rand() % (int)1040 + 110;
    int characterXposition2 = std::rand() % (int)1040 + 110;
    int characterXposition3 = std::rand() % (int)1040 + 110;
    charactersArray[0].area.setPosition(sf::Vector2f(characterXposition0, 30));
    charactersArray[1].area.setPosition(sf::Vector2f(characterXposition1, 30));
    charactersArray[2].area.setPosition(sf::Vector2f(characterXposition2, 30));
    charactersArray[3].area.setPosition(sf::Vector2f(characterXposition3, 30));
  }
  else if (current_map == 1)
  {
    charactersArray[0].area.setPosition(sf::Vector2f(300, 100));
    charactersArray[1].area.setPosition(sf::Vector2f(900, 100));
    charactersArray[2].area.setPosition(sf::Vector2f(500, 100));
    charactersArray[3].area.setPosition(sf::Vector2f(700, 100));
  }
  else if (current_map == 2)
  {
    charactersArray[0].area.setPosition(sf::Vector2f(100, 100));
    charactersArray[1].area.setPosition(sf::Vector2f(SCREENWIDTH - 130, 100));
    charactersArray[2].area.setPosition(sf::Vector2f(230, 100));
    charactersArray[3].area.setPosition(sf::Vector2f(SCREENWIDTH - 230, 100));
  }
  else
  {
    int characterXposition0 = std::rand() % (int)SCREENWIDTH;
    int characterXposition1 = std::rand() % (int)SCREENWIDTH;
    int characterXposition2 = std::rand() % (int)SCREENWIDTH;
    int characterXposition3 = std::rand() % (int)SCREENWIDTH;
    charactersArray[0].area.setPosition(sf::Vector2f(characterXposition0, 30));
    charactersArray[1].area.setPosition(sf::Vector2f(characterXposition1, 30));
    charactersArray[2].area.setPosition(sf::Vector2f(characterXposition2, 30));
    charactersArray[3].area.setPosition(sf::Vector2f(characterXposition3, 30));
  }
}

void move(Character &player)
{
  if (player.isMovingLeft)
  {

    if (!player.isFlying)
      player.playerVelocity.x = -1 * PLAYER_SPEED;
    player.isMoving = true;
    if (!player.isFacingLeft)
    {
      player.isFacingLeft = true;
      player.sprite.setScale(sf::Vector2f(-1.f, 1.f));
      player.sprite.setOrigin(sf::Vector2f(player.sprite.getGlobalBounds().width, 0));
    }
  }
  if (player.isMovingRight)
  {

    if (!player.isFlying)
      player.playerVelocity.x = PLAYER_SPEED;
    player.isMoving = true;
    if (player.isFacingLeft)
    {
      player.isFacingLeft = false;
      player.sprite.setScale(sf::Vector2f(1.f, 1.f));
      player.sprite.setOrigin(sf::Vector2f(0, 0));
    }
  }
  if (player.shallJump)
  {

    if (player.isOnBlock)
    {
      player.isOnBlock = false;
      player.playerVelocity.y = JUMP;
    }
  }
  if (player.isFlying)
  {
    if (player.playerVelocity.x > 0)
    {
      player.playerVelocity.x -= 2;
    }
    else if (player.playerVelocity.x < 0)
    {
      player.playerVelocity.x += 2;
    }
    else
      player.isFlying = false;
  }
  else if (player.isOnBlock)
  {
    player.playerVelocity.y = 0;
  }
  else
  {
    player.playerVelocity.y += GRAVITY.y;
  }

  if (!player.isMovingLeft && !player.isMovingRight && !player.isFlying)
  {
    player.isMoving = false;
    player.playerVelocity.x = 0;
  }
  player.area.move(player.playerVelocity);
}

void checkBlockCollision(Character &player)
{

  sf::Vector2f playerPosition = player.area.getPosition();
  auto playerBounds = player.area.getGlobalBounds();
  bool tmpIsOnBlock = false;

  for (int i = 0; i < map[current_map].num_of_blocks; i++)
  {
    auto blockBounds = map[current_map].blocks[i].block_area.getGlobalBounds();

    if (blockBounds.intersects(playerBounds) && !player.isOnBlock)
    {
      // Collision from top
      if (playerPosition.y < blockBounds.top)
      {
        player.area.setPosition(sf::Vector2f(playerPosition.x, blockBounds.top - playerBounds.height));
        tmpIsOnBlock = true;
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
    else if (blockBounds.top - playerBounds.height == player.area.getPosition().y &&
             blockBounds.left < playerBounds.left + playerBounds.width && blockBounds.width + blockBounds.left > playerBounds.left + playerBounds.width)
    {
      tmpIsOnBlock = true;
      break;
    }
  }
  player.isOnBlock = tmpIsOnBlock;
}

void checkScreenCollision(Character &player)
{

  if (player.area.getPosition().y <= 0)
  {
    player.area.setPosition(player.area.getPosition().x, 0);
  }
  else if (player.area.getPosition().y + player.area.getSize().y >= SCREENHEIGHT)
  {
    player.isDead = true;
  }
}

bool checkPlayerHitCollision(Character &player)
{
  auto playerBounds = player.sprite.getGlobalBounds();
  for (int i = 0; i < number_of_players; i++)
  {
    auto otherPlayer = charactersArray[i];
    auto otherPlayerBounds = otherPlayer.sprite.getGlobalBounds();

    if (otherPlayer.isDead)
      continue;
    if (playerBounds == otherPlayerBounds) // if same player skip
      continue;

    if (playerBounds.intersects(otherPlayerBounds))
    {
      if (otherPlayer.isPunshing && !otherPlayer.isFlying && !otherPlayer.isHavingGun)
      {
        player.playerVelocity.x = otherPlayer.isFacingLeft ? -10 : 10;
        return true;
      }
    }
  }
  return false;
}

void handlePlayerHitted(Character &player, int playerIndex)
{
  player.playerVelocity.y = JUMP / 4;
  player.isFlying = true;

  if (healthBarArray[playerIndex].currentHP > 0)
  {
    healthBarArray[playerIndex].currentHP -= 0.4f;
  }
}

void updatePlayerAnimation(Character &player)
{
  if (player.isFacingLeft)
    player.sprite.setPosition(player.area.getPosition() + sf::Vector2f(-18, 0));
  else
    player.sprite.setPosition(player.area.getPosition() + sf::Vector2f(-10, 0));

  if (player.isPunshing)
  {
    player.texturesLimt = 10;
    player.selectedIndex = 1;
  }
  else if (player.isMoving)
  {
    player.texturesLimt = 9;
    player.selectedIndex = 2;
  }
  else
  {
    player.texturesLimt = 6;
    player.selectedIndex = 0;
  }

  player.frames++;
  if (player.frames >= player.texturesLimt - 1)
    player.frames = 0;
}

void handelCharacterEvents(sf::Event &event)
{

  // Handle Key pressed
  if (event.type == sf::Event::KeyPressed)
  {

    switch (event.key.code)
    {
    case sf::Keyboard::A:
    {

      charactersArray[0].isMovingLeft = true;
      break;
    }
    case sf::Keyboard::D:
    {

      charactersArray[0].isMovingRight = true;
      break;
    }
    case sf::Keyboard::W:
      charactersArray[0].shallJump = true;
      break;
    case sf::Keyboard::E:
    {
      if (charactersArray[0].isHavingGun)
        charactersArray[0].isFiring = true;
      else
        charactersArray[0].isPunshing = true;
      break;
    }
    case sf::Keyboard::H:
      charactersArray[1].isMovingLeft = true;
      break;
    case sf::Keyboard::K:
      charactersArray[1].isMovingRight = true;
      break;
    case sf::Keyboard::U:
      charactersArray[1].shallJump = true;
      break;
    case sf::Keyboard::I:
    {
      if (charactersArray[1].isHavingGun)
        charactersArray[1].isFiring = true;
      else
        charactersArray[1].isPunshing = true;
      break;
    }
    case sf::Keyboard::Left:
      charactersArray[2].isMovingLeft = true;
      break;
    case sf::Keyboard::Right:
      charactersArray[2].isMovingRight = true;
      break;
    case sf::Keyboard::Up:
      charactersArray[2].shallJump = true;
      break;
    case sf::Keyboard::Numpad0:
    {
      if (charactersArray[2].isHavingGun)
        charactersArray[2].isFiring = true;
      else
        charactersArray[2].isPunshing = true;
      break;
    }
    case sf::Keyboard::Numpad4:
      charactersArray[3].isMovingLeft = true;
      break;
    case sf::Keyboard::Numpad6:
      charactersArray[3].isMovingRight = true;
      break;
    case sf::Keyboard::Numpad8:
      charactersArray[3].shallJump = true;
      break;
    case sf::Keyboard::Numpad9:
    {

      if (charactersArray[3].isHavingGun)
        charactersArray[3].isFiring = true;
      else
        charactersArray[3].isPunshing = true;
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
      {

      case sf::Keyboard::A:
        charactersArray[0].isMovingLeft = false;
        break;
      case sf::Keyboard::D:
        charactersArray[0].isMovingRight = false;
        break;
      case sf::Keyboard::W:
        charactersArray[0].shallJump = false;
        break;
      case sf::Keyboard::E:
        if (charactersArray[0].isHavingGun)
          charactersArray[0].isFiring = false;
        else
          charactersArray[0].isPunshing = false;
        break;
      }

      {
      case sf::Keyboard::K:
        charactersArray[1].isMovingRight = false;
        break;
      case sf::Keyboard::H:
        charactersArray[1].isMovingLeft = false;
        break;
      case sf::Keyboard::U:
        charactersArray[1].shallJump = false;
      case sf::Keyboard::I:
        if (charactersArray[1].isHavingGun)
          charactersArray[1].isFiring = false;
        else
          charactersArray[1].isPunshing = false;
        break;
      }

      {
      case sf::Keyboard::Left:
        charactersArray[2].isMovingLeft = false;
        break;
      case sf::Keyboard::Right:
        charactersArray[2].isMovingRight = false;
        break;
      case sf::Keyboard::Up:
        charactersArray[2].shallJump = false;
        break;
      case sf::Keyboard::Numpad0:
        if (charactersArray[2].isHavingGun)
          charactersArray[2].isFiring = false;
        else
          charactersArray[2].isPunshing = false;
        break;
      }

      {
      case sf::Keyboard::Numpad4:
        charactersArray[3].isMovingLeft = false;
        break;
      case sf::Keyboard::Numpad6:
        charactersArray[3].isMovingRight = false;
        break;
      case sf::Keyboard::Num8:
        charactersArray[3].shallJump = false;
        break;
      case sf::Keyboard::Numpad9:
        if (charactersArray[3].isHavingGun)
          charactersArray[3].isFiring = false;
        else
          charactersArray[3].isPunshing = false;
        break;
      }
    default:
      break;
    }
  }
}
