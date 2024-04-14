#include "Globals.hpp"
#include "screens/PlaySettings.hpp"
#include "components/Menu.hpp"
#include <string>

#define PLAY_SETTINGS_ITEMS_NUMBER 4
#define NUMBER_OF_PLAYERS_ITEMS_NUMBER 2

short current_opened_item_number = 0;

Menu numOfPMenu = initlizeNumberOfPlayersMenu();

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
            if (current_opened_item_number == 1)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    switch (numOfPMenu.selectedItem)
                    {
                    case 1:
                        current_opened_item_number = 0;
                        numOfPMenu.selectedItem = 0;
                        break;
                    default:
                        break;
                    }
                }
                if (event.key.code == sf::Keyboard::Right && numOfPMenu.selectedItem == 0)
                {
                    if (number_of_players < 4)
                        number_of_players++;
                }
                if (event.key.code == sf::Keyboard::Left && numOfPMenu.selectedItem == 0)
                {
                    if (number_of_players > 2)
                        number_of_players--;
                }

                updateMenu(numOfPMenu, event);
            }
            else
            {

                if (event.key.code == sf::Keyboard::Enter)
                {
                    switch (psMenu.selectedItem)
                    {
                    case 0:
                        psMenu.selectedItem = 0;
                        current_screen = 0;
                        break;
                    case 1:
                        current_opened_item_number = 1;
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
            }
            break;
        }
        default:
            break;
        }
    }
}

void playSettingsDraw(sf::RenderWindow &window, Menu &psManu)
{
    switch (current_opened_item_number)
    {
    case 0:
        drawMenu(psManu, window);
        break;
    case 1:
        numberOfPlayersDraw(window);
        break;

    default:
        break;
    }
}

void numberOfPlayersDraw(sf::RenderWindow &window)
{
    // Menu
    drawMenu(numOfPMenu, window);
    // Number of Players Counter
    sf::Text numText;
    numText.setFont(numOfPMenu.font);
    numText.setString(std::to_string(number_of_players));
    numText.setPosition(SCREENWIDTH / 2 - 200, SCREENHEIGHT / (numOfPMenu.numberOfItems + 1));
    numText.setColor(sf::Color::Magenta);
    window.draw(numText);
}

Menu initlizePlaySettingsMenu()
{
    char *settings[PLAY_SETTINGS_ITEMS_NUMBER] = {"Main Menu", "Number Of Players", "Map", "Start Game"};
    Menu menu = initlizeMenu(PLAY_SETTINGS_ITEMS_NUMBER, settings);
    return menu;
}

Menu initlizeNumberOfPlayersMenu()
{
    char *settings[PLAY_SETTINGS_ITEMS_NUMBER] = {"Change Number Of Players", "Go Back"};
    Menu menu = initlizeMenu(NUMBER_OF_PLAYERS_ITEMS_NUMBER, settings);
    return menu;
}