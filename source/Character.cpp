#include "components/Character.hpp"
#include "Globals.hpp"
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

void checkScreenCollision(Character &player)
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
    player.onGround = true;
    player.area.setPosition(player.area.getPosition().x, SCREENHEIGHT - player.area.getSize().y);
  }
}

void move(Character &player)
{
  player.area.move(player.playerVelocity);
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

      if (!charactersArray[0].isFlying)
        charactersArray[0].playerVelocity.x = -5;
      charactersArray[0].isMoving = true;
      if (!charactersArray[0].isFacingLeft)
      {
        charactersArray[0].isFacingLeft = true;
        charactersArray[0].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[0].sprite.setOrigin(sf::Vector2f(charactersArray[0].sprite.getGlobalBounds().width,
                                                         0));
      }
      break;
    }
    case sf::Keyboard::D:
    {

      if (!charactersArray[0].isFlying)
        charactersArray[0].playerVelocity.x = 5;
      charactersArray[0].isMoving = true;
      if (charactersArray[0].isFacingLeft)
      {
        charactersArray[0].isFacingLeft = false;
        charactersArray[0].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[0].sprite.setOrigin(sf::Vector2f(0, 0));
      }
      break;
    }
    case sf::Keyboard::W:
    {

      if (charactersArray[0].onGround || charactersArray[0].isOnBlock)
      {

        charactersArray[0].isOnBlock = false;
        charactersArray[0].onGround = false;
        charactersArray[0].playerVelocity.y = JUMP;
      }
      break;
    }
    case sf::Keyboard::E:
    {

      if (charactersArray[0].isHavingGun)
        charactersArray[0].isFiring = true;
      else
        charactersArray[0].isPunshing = true;
      break;
    }
      // Player 1
    case sf::Keyboard::H:
    {

      if (!charactersArray[1].isFlying)
        charactersArray[1].playerVelocity.x = -5;
      charactersArray[1].isMoving = true;
      if (!charactersArray[1].isFacingLeft)
      {
        charactersArray[1].isFacingLeft = !charactersArray[1].isFacingLeft;
        charactersArray[1].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[1].sprite.setOrigin(sf::Vector2f(charactersArray[1].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::K:
    {

      if (!charactersArray[1].isFlying)
        charactersArray[1].playerVelocity.x = 5;
      charactersArray[1].isMoving = true;
      if (charactersArray[1].isFacingLeft)
      {
        charactersArray[1].isFacingLeft = !charactersArray[1].isFacingLeft;
        charactersArray[1].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[1].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::U:
    {

      if (charactersArray[1].onGround || charactersArray[1].isOnBlock)
      {
        charactersArray[1].isOnBlock = false;
        charactersArray[1].onGround = false;
        charactersArray[1].playerVelocity.y = JUMP;
      }
      break;
    }
    case sf::Keyboard::I:
    {
      if (charactersArray[1].isHavingGun)
        charactersArray[1].isFiring = true;
      else
        charactersArray[1].isPunshing = true;
      break;
    }

      // Player 2
    case sf::Keyboard::Left:
    {

      if (!charactersArray[2].isFlying)
        charactersArray[2].playerVelocity.x = -5;
      charactersArray[2].isMoving = true;
      if (!charactersArray[2].isFacingLeft)
      {
        charactersArray[2].isFacingLeft = !charactersArray[2].isFacingLeft;
        charactersArray[2].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(charactersArray[2].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::Right:
    {

      if (!charactersArray[2].isFlying)
        charactersArray[2].playerVelocity.x = 5;
      charactersArray[2].isMoving = true;
      if (charactersArray[2].isFacingLeft)
      {
        charactersArray[2].isFacingLeft = !charactersArray[2].isFacingLeft;
        charactersArray[2].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[2].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::Up:
    {

      if (charactersArray[2].onGround || charactersArray[2].isOnBlock)
      {
        charactersArray[2].isOnBlock = false;
        charactersArray[2].onGround = false;
        charactersArray[2].playerVelocity.y = JUMP;
      }
      break;
    }
    case sf::Keyboard::Numpad0:
    {
      if (charactersArray[2].isHavingGun)
        charactersArray[2].isFiring = true;
      else
        charactersArray[2].isPunshing = true;
      break;
    }
      // Player 3
    case sf::Keyboard::Numpad4:
    {

      if (!charactersArray[3].isFlying)
        charactersArray[3].playerVelocity.x = -5;
      charactersArray[3].isMoving = true;
      if (!charactersArray[3].isFacingLeft)
      {
        charactersArray[3].isFacingLeft = !charactersArray[3].isFacingLeft;
        charactersArray[3].sprite.setScale(sf::Vector2f(-1.f, 1.f));
        charactersArray[3].sprite.setOrigin(sf::Vector2f(charactersArray[3].sprite.getGlobalBounds().width,
                                                         0));
      }
    }
    break;
    case sf::Keyboard::Numpad6:
    {

      if (!charactersArray[3].isFlying)
        charactersArray[3].playerVelocity.x = 5;
      charactersArray[3].isMoving = true;
      if (charactersArray[3].isFacingLeft)
      {
        charactersArray[3].isFacingLeft = !charactersArray[3].isFacingLeft;
        charactersArray[3].sprite.setScale(sf::Vector2f(1.f, 1.f));
        charactersArray[3].sprite.setOrigin(sf::Vector2f(0, 0));
      }
    }
    break;
    case sf::Keyboard::Numpad8:
    {

      if (charactersArray[3].onGround || charactersArray[3].isOnBlock)
      {
        charactersArray[3].isOnBlock = false;
        charactersArray[3].onGround = false;
        charactersArray[3].playerVelocity.y = JUMP;
      }
      break;
    }
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

    // Handle Key Released
  }
  if (event.type == sf::Event::KeyReleased)
  {

    switch (event.key.code)
    {

    // Player 0
    case sf::Keyboard::A:
    case sf::Keyboard::D:
      charactersArray[0].isMoving = false;
      charactersArray[0].playerVelocity.x = 0;
      break;
    case sf::Keyboard::E:
      if (charactersArray[0].isHavingGun)
        charactersArray[0].isFiring = false;
      else
        charactersArray[0].isPunshing = false;
      break;
    // Player 1
    case sf::Keyboard::K:
    case sf::Keyboard::H:
      charactersArray[1].isMoving = false;
      charactersArray[1].playerVelocity.x = 0;
      break;
    case sf::Keyboard::I:

      if (charactersArray[1].isHavingGun)
        charactersArray[1].isFiring = false;
      else
        charactersArray[1].isPunshing = false;
      break;
    // Player 2
    case sf::Keyboard::Left:
    case sf::Keyboard::Right:
      charactersArray[2].isMoving = false;
      charactersArray[2].playerVelocity.x = 0;
      break;
    case sf::Keyboard::Numpad0:
      if (charactersArray[2].isHavingGun)
        charactersArray[2].isFiring = false;
      else
        charactersArray[2].isPunshing = false;
      break;

    // Player 3
    case sf::Keyboard::Numpad4:
    case sf::Keyboard::Numpad6:
      charactersArray[3].isMoving = false;
      charactersArray[3].playerVelocity.x = 0;
      break;
    case sf::Keyboard::Numpad9:
      if (charactersArray[3].isHavingGun)
        charactersArray[3].isFiring = false;
      else
        charactersArray[3].isPunshing = false;
      break;
    default:
      break;
    }
  }
}

void checkBlockCollision(Character &player)
{

  sf::Vector2f playerPosition = player.area.getPosition();
  auto playerBounds = player.area.getGlobalBounds();

  for (int i = 0; i < map[current_map].num_of_blocks; i++)
  {
    auto blockBounds = map[current_map].blocks[i].block_area.getGlobalBounds();

    if (blockBounds.intersects(playerBounds) && !player.isOnBlock)
    {
      // Collision from top
      if (playerPosition.y < blockBounds.top)
      {
        player.area.setPosition(sf::Vector2f(playerPosition.x, blockBounds.top - playerBounds.height));
        player.isOnBlock = true;
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
      player.isOnBlock = false;
    }
  }
}

void checkPlayerHitCollision(Character &player)
{
  auto playerBounds = player.sprite.getGlobalBounds();
  for (int i = 0; i < number_of_players; i++)
  {
    if (charactersArray[i].isDead)
      continue;
    auto otherPlayerBounds = charactersArray[i].sprite.getGlobalBounds();

    // if same player then skip
    if (playerBounds == otherPlayerBounds)
      continue;
    if (playerBounds.intersects(otherPlayerBounds))
    {
      if (player.isPunshing && !player.isFlying && !player.isHavingGun)
      {

        charactersArray[i].playerVelocity.x = player.isFacingLeft ? -20 : 20;
        charactersArray[i].playerVelocity.y = JUMP / 4;
        charactersArray[i].isFlying = true;
        charactersArray[i].onGround = false;
        charactersArray[i].isDamaged.yes = true;
        charactersArray[i].isDamaged.damageQuantity = 3;
      }
    }
  }
}

void charactersUpdate(sf::RenderWindow &window)
{

  for (int i = 0; i < number_of_players; i++)
  {
    if (charactersArray[i].isDead)
      continue;
    move(charactersArray[i]);
    // Collision Checks
    checkScreenCollision(charactersArray[i]);
    checkBlockCollision(charactersArray[i]);
    checkPlayerHitCollision(charactersArray[i]);

    if (charactersArray[i].isFacingLeft)
      charactersArray[i].sprite.setPosition(charactersArray[i].area.getPosition() + sf::Vector2f(-18, 0));
    else
      charactersArray[i].sprite.setPosition(charactersArray[i].area.getPosition() + sf::Vector2f(-10, 0));

    if (charactersArray[i].isHavingGun)
    {
      charactersArray[i].texturesLimt = 0;
      charactersArray[i].selectedIndex = 3;
    }
    else if (charactersArray[i].isPunshing)
    {
      charactersArray[i].texturesLimt = 10;
      charactersArray[i].selectedIndex = 1;
    }
    else if (charactersArray[i].isMoving)
    {
      charactersArray[i].texturesLimt = 9;
      charactersArray[i].selectedIndex = 2;
    }
    else
    {
      charactersArray[i].texturesLimt = 6;
      charactersArray[i].selectedIndex = 0;
    }

    charactersArray[i].frames++;
    if (charactersArray[i].frames >= charactersArray[i].texturesLimt - 1)
      charactersArray[i].frames = 0;

    if (charactersArray[i].isOnBlock || charactersArray[i].onGround)
    {
      charactersArray[i].playerVelocity.y = 0;
    }
    else
    {
      charactersArray[i].playerVelocity.y += GRAVITY.y;
    }
    if (charactersArray[i].isFlying)
    {
      if (charactersArray[i].playerVelocity.x > 0)
      {
        charactersArray[i].playerVelocity.x -= 2;
      }
      else if (charactersArray[i].playerVelocity.x < 0)
      {
        charactersArray[i].playerVelocity.x += 2;
      }
      else
        charactersArray[i].isFlying = false;
    }

    // Handle hit
    if (charactersArray[i].isDamaged.yes && healthBarArray[i].currentHP > 0)
    {
      healthBarArray[i].currentHP -= charactersArray[i].isDamaged.damageQuantity;
      charactersArray[i].isDamaged.yes = false;
    }
  }
}
void charactersDraw(sf::RenderWindow &window)
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
