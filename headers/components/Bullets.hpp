#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

#define BULLET_1_TEXTURE "assets/images/weapons/weapon1.png"
#define MAX_BULLETS_NUMBER 100
#define BULLET_VELOCITY 10

struct Bullet
{
    sf::Vector2f position;
    sf::CircleShape area;
    sf::Sprite sprite;
    bool directionIsRight;
    int damage;
};

void createBullet(sf::Vector2f startPosition, bool directionIsRight, int damage);
void loadBulletsAssets();
void updateBullets();
void drawBullets(sf::RenderWindow &window);

#endif