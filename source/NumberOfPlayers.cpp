#include "screens/subscreens/NumberOfPlayers.hpp"

#define NUMBER_OF_PLAYERS_ITEMS_NUMBER 2

Menu numOfPMenu = initlizeNumberOfPlayersMenu();

void numberOfPlayersUpdate(sf::RenderWindow &window)
{

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Enter)
            {
                switch (numOfPMenu.selectedItem)
                {
                case 1:
                    current_screen = 1;
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
    }
}
void numberOfPlayersDraw(sf::RenderWindow &window)
{

    drawMenu(numOfPMenu, window, "Number of players menu");

    // Number of Players Counter
    sf::Text numText;
    numText.setFont(numOfPMenu.font);
    numText.setString(std::to_string(number_of_players));
    numText.setPosition(SCREENWIDTH / 2 - 200, SCREENHEIGHT / (numOfPMenu.numberOfItems + 1));
    numText.setColor(sf::Color::Magenta);
    window.draw(numText);
}

Menu initlizeNumberOfPlayersMenu()
{
    char *settings[NUMBER_OF_PLAYERS_ITEMS_NUMBER] = {"Change Number Of Players", "Go Back"};
    Menu menu = initlizeMenu(NUMBER_OF_PLAYERS_ITEMS_NUMBER, settings);
    return menu;
}