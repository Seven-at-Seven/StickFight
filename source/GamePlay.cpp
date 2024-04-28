#include "screens/GamePlay.hpp"
#include "Globals.hpp"
#include "components/Character.hpp"
#include "MapUtility.hpp"
#include "components/HealthBar.hpp"
#include "components/Weapons.hpp"

int current_map = 0;
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

                if (current_map == 5)
                    current_map = 0;

                else
                    current_map++;
            }
        }
    }
    charactersUpdate(window);
    updateWeapons();
    updateBullets();
}

void gamePlayDraw(sf::RenderWindow &window)
{
    switch (current_map)
    {
    case 0:
        drawMap(window, map[0], 4, 0);
        break;
    case 1:
        drawMap(window, map[1], 4, 3);
        break;
    case 2:
        drawMap(window, map[2], 4, 0);
        break;
    case 3:
        drawMap(window, map[3], 4, 0);
        break;
    case 4:
        drawMap(window, map[4], 4, 0);
        break;
    case 5:
        drawMap(window, map[5], 4, 0);
        break;
    default:
        break;
    }
    charactersDraw(window);
    drawHealthBar(window);
    drawWeapons(window);
    drawBullets(window);
}