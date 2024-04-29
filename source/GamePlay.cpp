#include "screens/GamePlay.hpp"
#include "Globals.hpp"
#include "components/Character.hpp"
#include "MapUtility.hpp"
#include "components/HealthBar.hpp"
#include "components/Weapons.hpp"

int current_map = 0;

void loadGamePlayAssets()
{

    loadCharacterAssets();
    loadMapAssets();
    loadHealthBarAssets();
    loadWeaponsAssets();
    loadBulletsAssets();
}

void gamePlayUpdate(sf::RenderWindow &window)
{

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
            if (event.key.code == sf::Keyboard::Space)
            {

                if (current_map == 4)
                    current_map = 0;

                else
                    current_map++;
            }
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