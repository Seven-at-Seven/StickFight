#ifndef WEPONES_H
#define WEPONES_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define WEPONES_1_TEXTURE "assets/images/weapons/weapon1.png"

struct Weapon
{
    sf::Vector2f weaponVelocity = sf::Vector2f(0, 0);
    sf::RectangleShape area;
    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Sound effect;

    bool isHeld = false;
    bool isSpawned = false;
    int ownerIndex = -1;
    bool isWeaponOnBlock = false;

    int speed;
    int damage;
};

void loadWeaponsAssets();
void spawnWeapons();
void restartWeapons();

void handleWeaponBlockCollision(Weapon *weapon);

void updateWeapons();
void drawWeapons(sf::RenderWindow &window);
#endif