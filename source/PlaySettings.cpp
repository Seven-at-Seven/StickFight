#include "Globals.hpp"
#include "screens/PlaySettings.hpp"
#include "components/Menu.hpp"
#include <string>

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

            if (event.key.code == sf::Keyboard::Enter)
            {
                switch (psMenu.selectedItem)
                {
                case 0:
                    last_screen = current_screen;
                    current_screen = 0;
                    break;
                case 1:
                    last_screen = current_screen;
                    current_screen = 5;
                    break;
                case 3:
                    last_screen = current_screen;
                    current_screen = 2;
                    break;

                default:
                    break;
                }
            }
            if (event.key.code == sf::Keyboard::Escape)
            {

                current_screen = last_screen;
                last_screen = 0;
            }
            updateMenu(psMenu, event);
            break;
        }
        default:
            break;
        }
    }
}

void playSettingsDraw(sf::RenderWindow &window, Menu &psMenu)
{
    drawMenu(psMenu, window, "Play Settings Menu");
}

Menu initlizePlaySettingsMenu()
{
    char *settings[PLAY_SETTINGS_ITEMS_NUMBER] = {"Main Menu", "Number Of Players", "Map", "Start Game"};
    Menu menu = initlizeMenu(PLAY_SETTINGS_ITEMS_NUMBER, settings);
    return menu;
}
