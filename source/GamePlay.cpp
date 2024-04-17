#include "screens/GamePlay.hpp"
#include "Globals.hpp"

int curmap = 0;
bool firsttime = true;
void gamePlayUpdate(sf::RenderWindow &window)
{

    if (firsttime)
    {
        loadingmap();
        firsttime = false;
    }
    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {

                current_screen = last_screen;
                last_screen = 0;
            }
            if (event.key.code == sf::Keyboard::A)
            {
                curmap--;
            }
            else if (event.key.code == sf::Keyboard::D)
            {
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
        window.draw(map[0].background_sprite);
        // window.draw(map[0].block[0].block_shape);
        // window.draw(map[1].block[1].block_shape);
        break;
    case 1:
        window.draw(map[1].background_sprite);
        break;
    case 2:
        window.draw(map[2].background_sprite);
        break;
    case 3:
        window.draw(map[3].background_sprite);
        break;
    case 4:
        window.draw(map[4].background_sprite);
        break;
    case 5:
        window.draw(map[5].background_sprite);
        break;
    default:
        window.draw(map[5].background_sprite);
        break;
    }
}