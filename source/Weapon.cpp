#include "components/Wepons.hpp"
#include "Configurations.hpp"
#include "Globals.hpp"
#include "string.h"
#include <iostream>

Weapon weaponArray[MAX_WEAPONS_NUMBER];

sf::Texture tex[MAX_WEAPONS_NUMBER];

struct WeaponState
{
    bool isHeld;
    int playerIndex;
};

// Weapon(s) states
sf::Vector2f weaponVelocity[MAX_WEAPONS_NUMBER];
short weaponCharacterMap[MAX_WEAPONS_NUMBER] = {};
WeaponState isWeaponHeld[MAX_WEAPONS_NUMBER] = {};
bool isweaponOnBlock[MAX_WEAPONS_NUMBER] = {};

void loadWeaponsAssets()
{
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {
        weaponArray[i].area.setPosition(sf::Vector2f(100 * i, 200));
        if (!tex[i].loadFromFile("assets/images/weapons/weapon" + std::to_string(i) + ".png"))
        {
            std::cout << "ERROR: Could not load" << std::endl;
        }
        weaponArray[i].sprite.setTexture(tex[i]);
        weaponArray[i].sprite.setTextureRect(sf::IntRect(4, 0, 64, 33));
        weaponArray[i].area.setSize(sf::Vector2f(64, 33));
    }
}

void checkPlayerWeaponCollision(int weaponIndex)
{
    auto weaponBounds = weaponArray[weaponIndex].sprite.getGlobalBounds();
    for (int i = 0; i < number_of_players; i++)
    {
        if (isHavingGun[i])
            continue;
        auto playerBounds = charactersArray[i].sprite.getGlobalBounds();
        if (playerBounds.intersects(weaponBounds))
        {
            isweaponOnBlock[weaponIndex] = false;
            isWeaponHeld[i].isHeld = true;
            isWeaponHeld[weaponIndex].playerIndex = i;
            isHavingGun[i] = true;
        }
    }
}
void updateWeapons()
{
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {

        weaponArray[i].area.move(weaponVelocity[i]);
        weaponArray[i].sprite.setPosition(weaponArray[i].area.getPosition());
        checkPlayerWeaponCollision(i);
        if (isWeaponHeld[i].isHeld)
        {

            weaponArray[i].area.setPosition(sf::Vector2f(
                charactersArray[isWeaponHeld[i].playerIndex].area.getPosition().x + 20,
                charactersArray[isWeaponHeld[i].playerIndex].area.getPosition().y));
        }
        else if (!isweaponOnBlock[i] && weaponArray[i].area.getPosition().y > SCREENHEIGHT)
        {
            isweaponOnBlock[i] = true;
            weaponArray[i].area.setPosition(sf::Vector2f(weaponArray[i].area.getPosition().x,
                                                         SCREENHEIGHT - weaponArray[i].area.getGlobalBounds().height));
            weaponVelocity[i].y = 0;
        }
        else if (!isweaponOnBlock[i])
        {
            weaponVelocity[i].y += GRAVITY.y / 2;
        }
    }
}
void drawWeapons(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {
        window.draw(weaponArray[i].sprite);
    }
}