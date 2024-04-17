#include "screens/GamePlay.hpp"
#include "components/Character.hpp"

int curmap = 0;
maps map[6];
void declaringmap()
{
    map[0].background.loadFromFile("assets/images/forest.jpg");
    map[1].background.loadFromFile("assets/images/background1.jpg");
    map[2].background.loadFromFile("assets/images/background2.png");
    map[3].background.loadFromFile("assets/images/background3.png");
    map[4].background.loadFromFile("assets/images/background4.png");
    map[5].background.loadFromFile("assets/images/background5.png");
    for (int i = 0; i < 6; i++)
    {
        map[i].background_sprite.setTexture(map[i].background);
        map[i].xdir = SCREENWIDTH / map[i].background_sprite.getGlobalBounds().width;
        map[i].ydir = SCREENHEIGHT / map[i].background_sprite.getGlobalBounds().height;
        map[i].background_sprite.setScale(sf::Vector2f(map[i].xdir, map[i].ydir));
    }
}
bool firsttime = true;
void gamePlayUpdate(sf::RenderWindow &window)
{

    if (firsttime)
    {
        declaringmap();
        firsttime = false;
    }
    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            window.close();

        handelCharacterEvents(character, event);
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
    characterUpdate(window, character, event);
}


   
void gamePlayDraw(sf::RenderWindow &window)
{
     characterDraw(window, character);
    switch (curmap)
    {
    case 0:
        window.draw(map[0].background_sprite);
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