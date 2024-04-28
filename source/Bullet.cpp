#include "Configurations.hpp"
#include "components/Bullets.hpp"
#include "Globals.hpp"

Bullet bulletsArray[MAX_BULLETS_NUMBER];
int bulletsIndeies[MAX_BULLETS_NUMBER] = {};
int lastBulletIndeiesElement = 0;

sf::Texture bulletTexture;

void loadBulletsAssets()
{
    bulletTexture.loadFromFile("assets/images/bullet.png");
}
void createBullet(sf::Vector2f startPosition, bool directionIsRight, int damage)
{
    for (int i = 0; i <= lastBulletIndeiesElement; i++)
    {
        if (bulletsIndeies[i] == 0)
        {
            bulletsIndeies[i] = 1;
            bulletsArray[i].sprite.setTexture(bulletTexture);
            bulletsArray[i].sprite.setTextureRect(sf::IntRect(0, 0, 40, 76));
            bulletsArray[i].position = startPosition;
            bulletsArray[i].directionIsRight = directionIsRight;
            bulletsArray[i].damage = damage;
            if (lastBulletIndeiesElement + 1 < MAX_BULLETS_NUMBER)
                lastBulletIndeiesElement++;
            break;
        }
    }
}

void destroyBullet(int bulletIndex)
{

    bulletsIndeies[bulletIndex] = 0;
    if (bulletIndex == lastBulletIndeiesElement)
        lastBulletIndeiesElement--;
}

void updateBullets()
{

    for (int i = 0; i <= lastBulletIndeiesElement; i++)
    {
        if (bulletsIndeies[i] != 0)
        {
            if (bulletsArray[i].directionIsRight)
            {
                auto newPosition = sf::Vector2f(bulletsArray[i].position.x + BULLET_VELOCITY, bulletsArray[i].position.y);
                bulletsArray[i].position = newPosition;
            }
            else
            {
                auto newPosition = sf::Vector2f(bulletsArray[i].position.x - BULLET_VELOCITY, bulletsArray[i].position.y);
                bulletsArray[i].position = newPosition;
            }
        }
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