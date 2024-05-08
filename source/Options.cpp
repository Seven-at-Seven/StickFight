#include "screens/Options.hpp"
#include "Globals.hpp"

#define OPTIONS_ITEMS_NUMBER 2

void optionsUpdate(sf::RenderWindow &window, Menu &opMenu)
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
                switch (opMenu.selectedItem)
                {
                case 0:
                    last_screen = current_screen;
                    opMenu.selectedItem = 0;
                    current_screen = 4;
                    break;
                case 1:
                    current_screen = 0;
                    break;
                default:
                    break;
                }
            }

            updateMenu(opMenu, event);
            break;
        }
        default:
            break;
        }
    }
}

// draw
void optionsDraw(sf::RenderWindow &window, Menu &opMenu)
{

    drawMenu(opMenu, window, "Options Menu");
}
Menu initlizeOptionsMenu()
{
    std::string options[OPTIONS_ITEMS_NUMBER] = {"Sound", "Back"};
    Menu menu = initlizeMenu(OPTIONS_ITEMS_NUMBER, options);
    return menu;
}