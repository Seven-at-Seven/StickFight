#include "../headers/screens/MainMenu.hpp"
#include "../headers/Globals.hpp"
#include <iostream>

#define MAIN_MENU_ITEMS_NUMBER 3

void mainUpdate(Menu &menu, int &current_screen, sf::RenderWindow &window)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    updateMenu(menu);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        switch (menu.selectedItem)
        {
        case 0:
            current_screen = 1;
            usleep(100000);
            break;
        case 1:
            current_screen = 3;
            usleep(100000);
            break;
        case 2:
            window.close();
        default:
            break;
        }
    }
}

Menu initlizeMainMenu()
{
    char *items[MAIN_MENU_ITEMS_NUMBER] = {"Play", "Options", "Exit"};
    Menu menu = initlizeMenu(MAIN_MENU_ITEMS_NUMBER, items);

    return menu;
}
void mainDraw(Menu &menu, sf::RenderWindow &window)
{

    drawMenu(menu, window);
}