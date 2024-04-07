#include "../headers/screens/Options.hpp"
#include "../headers/Globals.hpp"
#include <unistd.h>

#define OPTIONS_ITEMS_NUMBER 3

void optionsUpdate(sf::RenderWindow &window, Menu &opMenu)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    updateMenu(opMenu);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        switch (opMenu.selectedItem)
        {
        case 2:
            opMenu.selectedItem = 0;
            current_screen = 0;
            usleep(200000);
            break;
        default:
            break;
        }
    }
}

// draw
void optionsDraw(sf::RenderWindow &window, Menu &opMenu)
{
    drawMenu(opMenu, window);
}
Menu initlizeOptionsMenu()
{
    char *options[OPTIONS_ITEMS_NUMBER] = {"Sound", "Colors", "Main Menu"};
    Menu menu = initlizeMenu(OPTIONS_ITEMS_NUMBER, options);
    return menu;
}