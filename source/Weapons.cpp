#include "components/Weapons.hpp"
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

int timeBetweenAttacks = 0;

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
        if (isWeaponHeld[weaponIndex].isHeld)
            break;
        if (charactersArray[i].isHavingGun)
            continue;
        auto playerBounds = charactersArray[i].sprite.getGlobalBounds();
        if (playerBounds.intersects(weaponBounds))
        {
            isweaponOnBlock[weaponIndex] = false;
            isWeaponHeld[weaponIndex].isHeld = true;
            isWeaponHeld[weaponIndex].playerIndex = i;
            charactersArray[i].isHavingGun = true;
        }
    }
}
void fire(int weaponIndex, int playerIndex)
{
    if (timeBetweenAttacks == 0)
    {
        timeBetweenAttacks = 10;
        auto bulletSpawnPosition = sf::Vector2f(weaponArray[weaponIndex].area.getGlobalBounds().left,
                                                weaponArray[weaponIndex].area.getGlobalBounds().top);

        if (charactersArray[playerIndex].isFacingLeft)
        {
            bulletSpawnPosition.x -= charactersArray[playerIndex].area.getGlobalBounds().width;
        }
        createBullet(bulletSpawnPosition, !charactersArray[playerIndex].isFacingLeft, weaponArray[weaponIndex].damage);
        std::cout << "bullet number # " << lastBulletIndeiesElement << std::endl;
    }
    else
    {
        timeBetweenAttacks--;
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
            if (charactersArray[isWeaponHeld[i].playerIndex].isFiring)
            {
                fire(i, isWeaponHeld[i].playerIndex);
            }
            if (charactersArray[isWeaponHeld[i].playerIndex].isFacingLeft)
                weaponArray[i].sprite.setScale(sf::Vector2f(-1.0, 1.0));
            else
                weaponArray[i].sprite.setScale(sf::Vector2f(1.0, 1.0));
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