#include "components/Weapons.hpp"
#include "Configurations.hpp"
#include "Globals.hpp"
#include "string.h"
#include <iostream>

Weapon weaponArray[MAX_WEAPONS_NUMBER];

sf::Texture tex[MAX_WEAPONS_NUMBER];

int timeBetweenAttacks = 0;

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
        weaponArray[i].damage = 20;
    }
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

void spawnWeapons()
{

    for (int i = 0; i < 4; i++)
    {
        weaponArray[i].isHeld = false;
        weaponArray[i].isWeaponOnBlock = false;
    }
    if (current_map == 0)
    {
        weaponArray[0].area.setPosition(sf::Vector2f(100, 100));
        weaponArray[1].area.setPosition(sf::Vector2f(100 + 1 * 350, 100));
        weaponArray[2].area.setPosition(sf::Vector2f(100 + 2 * 350, 100));
        weaponArray[3].area.setPosition(sf::Vector2f(100 + 3 * 350, 100));
    }
    else if (current_map == 1)
    {

        weaponArray[0].area.setPosition(sf::Vector2f(300, 100));
        weaponArray[1].area.setPosition(sf::Vector2f(600, 100));
        weaponArray[2].area.setPosition(sf::Vector2f(200, 100));
        weaponArray[3].area.setPosition(sf::Vector2f(1000, 100));
    }
    else if (current_map == 2)
    {
        weaponArray[0].area.setPosition(sf::Vector2f(300, 100));
        weaponArray[1].area.setPosition(sf::Vector2f(600, 100));
        weaponArray[2].area.setPosition(sf::Vector2f(200, 100));
        weaponArray[3].area.setPosition(sf::Vector2f(1000, 100));
    }
    else
    {
        weaponArray[0].area.setPosition(sf::Vector2f(300, 100));
        weaponArray[1].area.setPosition(sf::Vector2f(600, 100));
        weaponArray[2].area.setPosition(sf::Vector2f(200, 100));
        weaponArray[3].area.setPosition(sf::Vector2f(1000, 100));
    }
}

void fire(int weaponIndex, int playerIndex)
{
    if (timeBetweenAttacks == 0)
    {
        timeBetweenAttacks = 10;
        auto bulletSpawnPosition = sf::Vector2f(weaponArray[weaponIndex].area.getGlobalBounds().left,
                                                weaponArray[weaponIndex].area.getGlobalBounds().top + 5);

        bulletSpawnPosition.x += charactersArray[playerIndex].isFacingLeft ? -1 * charactersArray[playerIndex].area.getGlobalBounds().width
                                                                           : charactersArray[playerIndex].area.getGlobalBounds().width;
        createBullet(bulletSpawnPosition, charactersArray[playerIndex].isFacingLeft,
                     weaponArray[weaponIndex].damage, playerIndex);
    }
    else
        timeBetweenAttacks--;
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

        if (!currentWeapon->isWeaponOnBlock)
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