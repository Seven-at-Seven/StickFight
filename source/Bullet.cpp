#include "Configurations.hpp"
#include "components/Bullets.hpp"
#include "Globals.hpp"
#include <iostream>

Bullet bulletsArray[MAX_BULLETS_NUMBER];
int bulletsIndeies[MAX_BULLETS_NUMBER] = {};
int lastBulletIndeiesElement = 0;

sf::Texture bulletTexture[4];

void loadBulletsAssets()
{

    for (int i = 0; i < 4; i++)
    {

        bulletTexture[i].loadFromFile("assets/images/bullet.png");
        // Get textures size
        sf::Vector2u textureSize = bulletTexture[i].getSize();

        // Create an image from the textures
        sf::Image image = bulletTexture[i].copyToImage();

        // Loop through each pixel
        for (unsigned int y = 0; y < textureSize.y; ++y)
        {
            for (unsigned int x = 0; x < textureSize.x; ++x)
            {
                // Get current pixel color
                sf::Color pixelColor = image.getPixel(x, y);

                // Check if black (all color components are 0)
                if (pixelColor.r == 255 && pixelColor.g == 244 && pixelColor.b == 0)
                {
                    // Change to red
                    image.setPixel(x, y, charactersArray[i].color);
                }
            }
        }
        bulletTexture[i].update(image);
    }
}
void createBullet(sf::Vector2f startPosition, bool facingLeft, int damage, int palyerIndex)
{
    for (int i = 0; i <= lastBulletIndeiesElement; i++)
    {
        if (bulletsIndeies[i] == 0)
        {
            bulletsIndeies[i] = 1;
            bulletsArray[i].sprite.setTexture(bulletTexture[palyerIndex]);
            bulletsArray[i].sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
            bulletsArray[i].position = startPosition;
            bulletsArray[i].sprite.setPosition(startPosition);
            bulletsArray[i].facingLeft = facingLeft;
            bulletsArray[i].damage = damage;
            bulletsArray[i].shooterIndex = palyerIndex;
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
    for (int i = 0; i < number_of_players; i++)
    {
        if (charactersArray[i].isDead || i == bulletsArray[bulletIndex].shooterIndex)
            continue;
        auto playerBounds = charactersArray[i].area.getGlobalBounds();

        if (bulletBounds.intersects(playerBounds) && bulletsIndeies[bulletIndex] != 0)
        {
            charactersArray[i].isDamaged = true;
            charactersArray[i].damageQuantity = bulletsArray[i].damage;
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