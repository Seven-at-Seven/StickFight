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
        weaponArray[i].area.setPosition(sf::Vector2f(100 * i, 200));
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
            weaponArray[weaponIndex].isWeaponHeld.isHeld = true;
            weaponArray[weaponIndex].isWeaponHeld.playerIndex = i;
            charactersArray[i].isHavingGun = true;
        }
    }
}

void spawnWeapons()
{

    if (current_map == 0)
    {
        weaponArray[0].area.setPosition(sf::Vector2f(100, 100));
        weaponArray[1].area.setPosition(sf::Vector2f(200, 100));
        weaponArray[2].area.setPosition(sf::Vector2f(300, 100));
        weaponArray[3].area.setPosition(sf::Vector2f(400, 100));
    }
    else if (current_map == 1)
    {
    }
    else if (current_map == 2)
    {
    }
    else
    {
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
        createBullet(bulletSpawnPosition, charactersArray[playerIndex].isFacingLeft, weaponArray[weaponIndex].damage);
        std::cout << "Bullet #" << lastBulletIndeiesElement << std::endl;
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

        // drop weapon if player is dead
        if (weaponArray[i].isWeaponHeld.isHeld && charactersArray[weaponArray[i].isWeaponHeld.playerIndex].isDead)
        {
            Character *player = &charactersArray[weaponArray[i].isWeaponHeld.playerIndex];
            player->area.setPosition(sf::Vector2f(player->area.getPosition().x, 0));
            player->isHavingGun = false;
            weaponArray[i].isWeaponHeld.isHeld = false;
            weaponArray[i].isWeaponOnBlock = false;
            continue;
        }
        weaponArray[i].area.move(weaponArray[i].weaponVelocity);
        weaponArray[i].sprite.setPosition(weaponArray[i].area.getPosition());

        if (!weaponArray[i].isWeaponHeld.isHeld)
            checkPlayerWeaponCollision(i);
        if (weaponArray[i].isWeaponHeld.isHeld)
        {

            weaponArray[i].area.setPosition(sf::Vector2f(
                charactersArray[weaponArray[i].isWeaponHeld.playerIndex].area.getPosition().x + 20,
                charactersArray[weaponArray[i].isWeaponHeld.playerIndex].area.getPosition().y));
            if (charactersArray[weaponArray[i].isWeaponHeld.playerIndex].isFiring)
            {
                fire(i, weaponArray[i].isWeaponHeld.playerIndex);
            }
            if (charactersArray[weaponArray[i].isWeaponHeld.playerIndex].isFacingLeft)
                weaponArray[i].sprite.setScale(sf::Vector2f(-1.0, 1.0));
            else
                weaponArray[i].sprite.setScale(sf::Vector2f(1.0, 1.0));
        }
        else if (!weaponArray[i].isWeaponOnBlock && weaponArray[i].area.getPosition().y > SCREENHEIGHT)
        {
            weaponArray[i].isWeaponOnBlock = true;
            weaponArray[i].area.setPosition(sf::Vector2f(weaponArray[i].area.getPosition().x,
                                                         SCREENHEIGHT - weaponArray[i].area.getGlobalBounds().height));
            weaponArray[i].weaponVelocity.y = 0;
        }
        else if (!weaponArray[i].isWeaponOnBlock)
        {
            weaponArray[i].weaponVelocity.y += GRAVITY.y / 2;
        }
    }
}

bool firstDraw = true;

void drawWeapons(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_WEAPONS_NUMBER; i++)
    {
        window.draw(weaponArray[i].sprite);
    }
}