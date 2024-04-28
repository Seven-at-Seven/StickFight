#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

#define BULLET_1_TEXTURE "assets/images/weapons/weapon1.png"

struct Bullet
{
    sf::Vector2f position;
    sf::CircleShape area;
    sf::Sprite sprite;
    int damage;
};

void loadBulletsAssets();
void updateBullets();
void drawBullets(sf::RenderWindow &window);

#endif