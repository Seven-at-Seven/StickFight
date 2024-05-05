#include "components/Weapons.hpp"
#include "Configurations.hpp"
#include "Globals.hpp"
#include "string.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Weapon weaponArray[MAX_WEAPONS_NUMBER];

sf::Texture tex[MAX_WEAPONS_NUMBER];

int timeBetweenAttacks[MAX_WEAPONS_NUMBER] = {3, 6, 15, 20};
int awaitedWeapon = 0;
int weaponTimer = 20;

void loadWeaponsAssets()
{
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {
        if (!tex[i].loadFromFile("assets/images/weapons/weapon" + std::to_string(i) + ".png"))
        {
            std::cout << "ERROR: Could not load" << std::endl;
        }
        weaponArray[i].sprite.setTexture(tex[i]);
        weaponArray[i].sprite.setTextureRect(sf::IntRect(4, 0, 64, 33));
        weaponArray[i].area.setSize(sf::Vector2f(64, 33));
    }
    weaponArray[0].damage = 3;
    weaponArray[0].speed = 2;

    weaponArray[1].speed = 6;
    weaponArray[1].damage = 6;

    weaponArray[2].speed = 15;
    weaponArray[2].damage = 20;

    weaponArray[3].speed = 20;
    weaponArray[3].damage = 34;
}

void checkPlayerWeaponCollision(int weaponIndex)
{

    auto weaponBounds = weaponArray[weaponIndex].sprite.getGlobalBounds();
    for (int i = 0; i < number_of_players; i++)
    {
        if (charactersArray[i].isHavingGun || charactersArray[i].isDead)
            continue;
        auto playerBounds = charactersArray[i].sprite.getGlobalBounds();
        if (playerBounds.intersects(weaponBounds))
        {
            weaponArray[weaponIndex].isWeaponOnBlock = false;
            weaponArray[weaponIndex].isHeld = true;
            weaponArray[weaponIndex].ownerIndex = i;
            charactersArray[i].isHavingGun = true;
        }
    }
}

void restartWeapons()
{

    awaitedWeapon = 0;
    weaponTimer = 20;
    for (int i = 0; i < 4; i++)
    {
        weaponArray[i].area.setPosition(sf::Vector2f(500, -200));
        weaponArray[i].sprite.setPosition(weaponArray[i].area.getPosition());
        weaponArray[i].isHeld = false;
        weaponArray[i].isWeaponOnBlock = false;
        weaponArray[i].isSpawned = false;
        weaponArray[i].weaponVelocity.y = 0;
    }
}
void spawnWeapons()
{

    if (awaitedWeapon > 3)
        return;
    if (weaponTimer == 0)
    {
        weaponTimer = 150;
        int weaponXPosition = std::rand() % (int)SCREENWIDTH;
        if (current_map == 1)
        {
            if (weaponXPosition < 280)
            weaponXPosition = 280;
            if (weaponXPosition > 909)
            {
                weaponXPosition = 909;
            }
        }
        
        weaponArray[awaitedWeapon].area.setPosition(sf::Vector2f(weaponXPosition, 0));
        weaponArray[awaitedWeapon].sprite.setPosition(sf::Vector2f(weaponXPosition, 0));

        weaponArray[awaitedWeapon].isSpawned = true;

        std::cout << "Spwan weapon at :" << weaponXPosition << std::endl;
        awaitedWeapon++;
    }
    else
        weaponTimer--;
}

void fire(int weaponIndex, int playerIndex)
{
    if (timeBetweenAttacks[weaponIndex] == 0)
    {
        timeBetweenAttacks[weaponIndex] = weaponArray[weaponIndex].speed;
        auto bulletSpawnPosition = sf::Vector2f(weaponArray[weaponIndex].area.getGlobalBounds().left,
                                                weaponArray[weaponIndex].area.getGlobalBounds().top + 5);

        bulletSpawnPosition.x += charactersArray[playerIndex].isFacingLeft ? -1 * charactersArray[playerIndex].area.getGlobalBounds().width
                                                                           : charactersArray[playerIndex].area.getGlobalBounds().width;
        createBullet(bulletSpawnPosition, charactersArray[playerIndex].isFacingLeft,
                     weaponArray[weaponIndex].damage, playerIndex);
    }
    else
        timeBetweenAttacks[weaponIndex]--;
}

void handleWeaponBlockCollision(Weapon *weapon)
{
    auto weaponBounds = weapon->area.getGlobalBounds();
    for (int i = 0; i < map[current_map].num_of_blocks; i++)
    {
        auto blockBounds = map[current_map].blocks[i].block_area.getGlobalBounds();

        if (blockBounds.intersects(weaponBounds))
        {

            auto newPosition = sf::Vector2f(weapon->area.getPosition().x,
                                            blockBounds.top - weapon->area.getGlobalBounds().height);
            weapon->isWeaponOnBlock = true;
            weapon->area.setPosition(newPosition);
            weapon->weaponVelocity.y = 0;
        }
    }
}

void updateWeapons()
{
    spawnWeapons();
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {
        auto currentWeapon = &weaponArray[i];

        handleWeaponBlockCollision(currentWeapon);

        if (currentWeapon->isHeld)
        {

            Character *gunOwner = &charactersArray[currentWeapon->ownerIndex];

            if (gunOwner->isDead)
            {

                gunOwner->area.setPosition(sf::Vector2f(gunOwner->area.getPosition().x, 0));
                gunOwner->isHavingGun = false;
                currentWeapon->isHeld = false;
                currentWeapon->isWeaponOnBlock = false;
                continue;
            }

            auto newPosition = sf::Vector2f(gunOwner->area.getPosition().x + 20,
                                            gunOwner->area.getPosition().y + 10);

            currentWeapon->area.setPosition(newPosition);

            if (gunOwner->isFiring)
                fire(i, currentWeapon->ownerIndex);

            if (gunOwner->isFacingLeft)
                currentWeapon->sprite.setScale(sf::Vector2f(-1.0, 1.0));

            else
                currentWeapon->sprite.setScale(sf::Vector2f(1.0, 1.0));
        }

        else
        {

            checkPlayerWeaponCollision(i);
            currentWeapon->area.move(currentWeapon->weaponVelocity);
            currentWeapon->sprite.setPosition(currentWeapon->area.getPosition());
        }

        if (!currentWeapon->isWeaponOnBlock && currentWeapon->isSpawned &&
            !currentWeapon->isHeld)
        {
            currentWeapon->weaponVelocity.y += GRAVITY.y / 7;
        }
        currentWeapon->sprite.setPosition(currentWeapon->area.getPosition());
    }
}

void drawWeapons(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {
        window.draw(weaponArray[i].sprite);
    }
}