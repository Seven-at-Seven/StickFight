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
  sf::Clock clock;
  character.rect.setPosition(206.0f, 206.0f);
  sf::Texture playerTexture;
  playerTexture.loadFromFile("assets/StickmanPack/Idle/thickIdleSheet.png");
  character.rect.setTexture(&playerTexture);
  Animation animation(&playerTexture, sf::Vector2u(5, 1), 0.2f);
  float deltaTime = 0.0f;

  deltaTime = clock.restart().asSeconds();

  animation.Update(0, deltaTime);
  character.rect.setTextureRect(animation.uvRect);
  window.draw(character.rect);
}

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
  this->imageCount = imageCount;
  this->switchTime = switchTime;
  totalTime = 0.0f;
  currentImage.x = 0;
  uvRect.width = texture->getSize().x / float(imageCount.x);
  uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::Update(int row, float deltaTime)
{
  currentImage.y = row;
  totalTime += deltaTime;
  if (totalTime >= switchTime)
  {
    totalTime -= switchTime;
    currentImage.x++;
    {
      if (currentImage.x >= imageCount.x)
        currentImage.x = 0;
    }
  }
  uvRect.left = currentImage.x * uvRect.width;
  uvRect.top = currentImage.y * uvRect.height;
}