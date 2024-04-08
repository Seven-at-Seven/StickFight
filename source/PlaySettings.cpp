#include "Globals.hpp"
#include "screens/PlaySettings.hpp"

#define PLAY_SETTINGS_ITEMS_NUMBER 4

void playSettingsUpdate(sf::RenderWindow &window, Menu &psMenu)
{

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyReleased:
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                switch (psMenu.selectedItem)
                {
                case 0:
                    psMenu.selectedItem = 0;
                    current_screen = 0;
                    break;
                case 3:
                    psMenu.selectedItem = 0;
                    current_screen = 2;
                    break;

                default:
                    break;
                }
            }
            updateMenu(psMenu, event);
            break;
        }
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