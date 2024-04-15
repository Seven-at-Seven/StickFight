#include "../headers/screens/MainMenu.hpp"
#include "../headers/Globals.hpp"

#define MAIN_MENU_ITEMS_NUMBER 3

bool firstLoad = true;
void mainUpdate(Menu &menu, int &current_screen, sf::RenderWindow &window)
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

            // If first load don't check for KeyRelease Enter
            if (firstLoad)
            {
                firstLoad = false;
                continue;
            }
            else if (event.key.code == sf::Keyboard::Enter)
            {
                switch (menu.selectedItem)
                {
                case 0:
                    current_screen = 1;
                    break;
                case 1:
                    current_screen = 3;
                    break;
                case 2:
                    window.close();
                default:
                    break;
                }
            }
            updateMenu(menu, event);
            break;
        }
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

    drawMenu(menu, window, "Main Menu");
}