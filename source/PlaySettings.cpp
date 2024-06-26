#include "Globals.hpp"
#include "screens/PlaySettings.hpp"
#include "components/Menu.hpp"

#define PLAY_SETTINGS_ITEMS_NUMBER 3

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
                    current_screen = 9;
                    break;
                case 1:
                    last_screen = current_screen;
                    current_screen = 5;
                    break;
                case 2:
                    last_screen = current_screen;
                    current_screen = 0;
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

void playSettingsDraw(sf::RenderWindow &window, Menu &psMenu)
{
    drawMenu(psMenu, window, "Settings Menu");
}

Menu initlizePlaySettingsMenu()
{
    std::string settings[PLAY_SETTINGS_ITEMS_NUMBER] = {"Go!", "Number Of Players", "Back"};
    Menu menu = initlizeMenu(PLAY_SETTINGS_ITEMS_NUMBER, settings);
    return menu;
}
