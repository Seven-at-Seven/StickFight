#ifndef WEPONES_H
#define WEPONES_H
#include <SFML/Graphics.hpp>

#define WEPONES_1_TEXTURE "assets/images/weapons/weapon1.png"

struct Weapon
{
    sf::Vector2f position;
    sf::RectangleShape area;
    sf::Sprite sprite;
    int damage;
};

void loadWeaponsAssets();
void updateWeapons(int weaponIndex);
void drawWeapons(sf::RenderWindow &window);

#endif