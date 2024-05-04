#include "screens/GamePlay.hpp"
#include "Globals.hpp"
#include "components/Character.hpp"
#include "MapUtility.hpp"
#include "components/HealthBar.hpp"
#include "components/Weapons.hpp"
#include <iostream>

int current_map = 0;
int alive_counter = number_of_players;
int round_over_timer = 30;

void restartGamePlay()
{
    spawnCharacters();
    restartWeapons();
}

void loadGamePlayAssets()
{
    loadCharacterAssets();
    loadMapAssets();
    loadHealthBarAssets();
    loadWeaponsAssets();
    loadBulletsAssets();
    restartGamePlay();
}

void gamePlayUpdate(sf::RenderWindow &window)
{
    alive_counter = number_of_players;
    for (int i = 0; i < number_of_players; i++)
    {
        if (charactersArray[i].isDead)
            alive_counter--;
    }
    if (alive_counter <= 1)
    {
        if (round_over_timer == 0)
        {
            round_over_timer = 30;
            if (current_map == 3)
            {
                current_screen = 0;
                current_map = 0;
                restartGamePlay();
            }
            else
            {

                current_map++;
                restartGamePlay();
            }
        }
        else
            round_over_timer--;
    }

    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            window.close();

        handelCharacterEvents(event);
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {

                current_screen = last_screen;
                last_screen = 0;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            std::cout << "x is :" << event.mouseButton.x << std::endl;
            std::cout << "y is :" << event.mouseButton.y << std::endl;
        }
    }
    updateCharacters();
    updateWeapons();
    updateBullets();
}

void gamePlayDraw(sf::RenderWindow &window)
{

    drawMap(window);
    drawCharacters(window);
    drawHealthBar(window);
    drawWeapons(window);
    drawBullets(window);
}