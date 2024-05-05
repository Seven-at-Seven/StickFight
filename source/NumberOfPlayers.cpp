#include "screens/subscreens/NumberOfPlayers.hpp"
#include "Globals.hpp"
#include "Configurations.hpp"
#include "screens/Register.hpp"

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
                    last_screen = current_screen;
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
                {

                    number_of_players++;
                    loadRegisterAssets();
                }
            }
            if (event.key.code == sf::Keyboard::Left && numOfPMenu.selectedItem == 0)
            {
                if (number_of_players > 2)
                {
                    loadRegisterAssets();

                    number_of_players--;
                }
            }

            updateMenu(numOfPMenu, event);
        }
    }
}

void numberOfPlayersDraw(sf::RenderWindow &window)
{
    drawMenu(numOfPMenu, window, "Number of players");

    // Number of Players Counter
    sf::Text numText;
    numText.setFont(numOfPMenu.font);
    numText.setString(std::to_string(number_of_players));
    numText.setPosition(SCREENWIDTH / 2 - numText.getLocalBounds().width / 2, SCREENHEIGHT / 2 - numText.getLocalBounds().height / 2);
    numText.setColor(sf::Color::White);
    window.draw(numText);

    // Right and Left Text
    sf::Text rightText;
    rightText.setFont(numOfPMenu.font);
    rightText.setString(" ->");
    rightText.setPosition(SCREENWIDTH / 2 + numText.getLocalBounds().width / 2 + 10, SCREENHEIGHT / 2 - numText.getLocalBounds().height / 2);
    rightText.setColor(sf::Color::White);
    window.draw(rightText);

    sf::Text leftText;
    leftText.setFont(numOfPMenu.font);
    leftText.setString("<- ");
    leftText.setPosition(SCREENWIDTH / 2 - numText.getLocalBounds().width / 2 - 10 - leftText.getLocalBounds().width, SCREENHEIGHT / 2 - numText.getLocalBounds().height / 2);
    leftText.setColor(sf::Color::White);
    window.draw(leftText);
}

Menu initlizeNumberOfPlayersMenu()
{
    char *settings[NUMBER_OF_PLAYERS_ITEMS_NUMBER] = {"Change Number Of Players", "Back"};
    Menu menu = initlizeMenu(NUMBER_OF_PLAYERS_ITEMS_NUMBER, settings);
    return menu;
}