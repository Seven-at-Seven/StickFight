#include "Globals.hpp"
#include "screens/PlaySettings.hpp"

#define PLAY_SETTINGS_ITEMS_NUMBER 4

void playSettingsUpdate(sf::RenderWindow &window, Menu &psMenu)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    updateMenu(psMenu);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        switch (psMenu.selectedItem)
        {
        case 0:
            psMenu.selectedItem = 0;
            current_screen = 0;
            usleep(200000);
            break;
        case 3:
            psMenu.selectedItem = 0;
            current_screen = 2;
            usleep(200000);
            break;

        default:
            break;
        }
    }
}

void playSettingsDraw(sf::RenderWindow &window, Menu &psManu)
{
    drawMenu(psManu, window);
}

Menu initlizePlaySettingsMenu()
{
    char *settings[PLAY_SETTINGS_ITEMS_NUMBER] = {"Main Menu", "Number Of Players", "Map", "Start Game"};
    Menu menu = initlizeMenu(PLAY_SETTINGS_ITEMS_NUMBER, settings);
    return menu;
}