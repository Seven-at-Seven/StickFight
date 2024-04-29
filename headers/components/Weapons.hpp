#ifndef WEPONES_H
#define WEPONES_H
#include <SFML/Graphics.hpp>

#define WEPONES_1_TEXTURE "assets/images/weapons/weapon1.png"

struct WeaponState
{
    bool isHeld;
    int playerIndex;
};
struct Weapon
{
    sf::Vector2f weaponVelocity;
    sf::RectangleShape area;
    sf::Vector2f position;
    sf::Sprite sprite;

    WeaponState isWeaponHeld = {};

    bool isWeaponOnBlock = false;
    int damage;
};

void loadWeaponsAssets();
void updateWeapons();
void drawWeapons(sf::RenderWindow &window);

#endif