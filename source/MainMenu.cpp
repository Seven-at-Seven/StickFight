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
                    last_screen = current_screen;
                    current_screen = 1;
                    break;
                case 1:
                    last_screen = current_screen;
                    current_screen = 3;
                    break;
                case 2:
                    window.close();
                default:
                    break;
                }
            }
            if (event.key.code == sf::Keyboard::Escape)
            {

                current_screen = last_screen;
                last_screen = 0;
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