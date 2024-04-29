#include "Configurations.hpp"
#include "components/Bullets.hpp"
#include "Globals.hpp"
#include <iostream>

Bullet bulletsArray[MAX_BULLETS_NUMBER];
int bulletsIndeies[MAX_BULLETS_NUMBER] = {};
int lastBulletIndeiesElement = 0;

sf::Texture bulletTexture;

void loadBulletsAssets()
{
    bulletTexture.loadFromFile("assets/images/bullet.png");
}
void createBullet(sf::Vector2f startPosition, bool facingLeft, int damage)
{
    for (int i = 0; i <= lastBulletIndeiesElement; i++)
    {
        if (bulletsIndeies[i] == 0)
        {
            bulletsIndeies[i] = 1;
            bulletsArray[i].sprite.setTexture(bulletTexture);
            bulletsArray[i].sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
            bulletsArray[i].position = startPosition;
            bulletsArray[i].sprite.setPosition(startPosition);
            bulletsArray[i].facingLeft = facingLeft;
            bulletsArray[i].damage = damage;
            if (i == lastBulletIndeiesElement && lastBulletIndeiesElement + 1 < MAX_BULLETS_NUMBER)
                lastBulletIndeiesElement++;
            break;
        }
    }
}

void destroyBullet(int bulletIndex)
{

    bulletsIndeies[bulletIndex] = 0;
    bulletsArray[bulletIndex].position = sf::Vector2f(0, 0);
}

void handleBulletPlayerCollision(int bulletIndex)
{
    auto bulletBounds = bulletsArray[bulletIndex].sprite.getGlobalBounds();
    for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
    {
        if (charactersArray[i].isDead)
            continue;
        auto playerBounds = charactersArray[i].area.getGlobalBounds();

        if (bulletBounds.intersects(playerBounds) && bulletsIndeies[bulletIndex] != 0)
        {
            std::cout << "interscet with player" << i << std::endl;
            charactersArray[i].isDamaged.yes = true;
            charactersArray[i].isDamaged.damageQuantity = bulletsArray[i].damage;
            destroyBullet(bulletIndex);
            break;
        }
    }
}
void updateBullets()
{

    for (int i = 0; i <= lastBulletIndeiesElement; i++)
    {
        if (bulletsIndeies[i] != 0)
        {
            if (bulletsArray[i].facingLeft)
            {
                auto newPosition = sf::Vector2f(bulletsArray[i].position.x - BULLET_VELOCITY, bulletsArray[i].position.y);
                bulletsArray[i].position = newPosition;
            }
            else
            {
                auto newPosition = sf::Vector2f(bulletsArray[i].position.x + BULLET_VELOCITY, bulletsArray[i].position.y);
                bulletsArray[i].position = newPosition;
            }
            if (bulletsArray[i].position.x > SCREENWIDTH || bulletsArray[i].position.x < 0)
            {
                destroyBullet(i);
            }
            handleBulletPlayerCollision(i);
        }
        if (lastBulletIndeiesElement > 0 && bulletsIndeies[lastBulletIndeiesElement - 1] == 0)
            lastBulletIndeiesElement--;
    }
}
void drawBullets(sf::RenderWindow &window)
{
    for (int i = 0; i <= lastBulletIndeiesElement; i++)
    {
        if (bulletsIndeies[i] != 0)
        {
            bulletsArray[i].sprite.setPosition(bulletsArray[i].position);
            window.draw(bulletsArray[i].sprite);
        }
    }
}