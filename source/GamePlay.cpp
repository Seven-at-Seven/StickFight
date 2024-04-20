#include "screens/GamePlay.hpp"
#include "components/Character.hpp"
#include "Globals.hpp"
#include "components/Block.hpp"
#include "Map_utility.hpp"

int curmap = 0;
Block myBlock;
void gamePlayUpdate(sf::RenderWindow &window)
{

    charactersUpdate(window);
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

               if(curmap==5)
                   curmap = 0;
               
               else
                   curmap++;
                   
            }
        }
    }
}

void gamePlayDraw(sf::RenderWindow &window)
{
    switch (curmap)
    {
    case 0:
        drawMap(window, map[0]);
        break;
    case 1:
        drawMap(window, map[1]);
        break;
    case 2:
        drawMap(window, map[2]);
        break;
    case 3:
        drawMap(window, map[3]);
        break;
    case 4:
        drawMap(window, map[4]);
        break;
    case 5:
        drawMap(window, map[5]);
        break;
    default:
        break;
    }
    charactersDraw(window);
}