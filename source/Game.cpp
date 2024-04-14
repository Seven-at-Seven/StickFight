#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include "screens/MainMenu.hpp"                   // Page 0
#include "screens/PlaySettings.hpp"               // Page 1
#include "screens/GamePlay.hpp"                   // Page 2
#include "screens/Options.hpp"                    // Page 3
#include "screens/Sound.hpp"                      // page 4
#include "screens/subscreens/NumberOfPlayers.hpp" // Page 5

// Global states

int current_screen = 0;
int number_of_players = 2;
sf::Event event;

// Menus

Menu mainMenu = initlizeMainMenu();
Menu opMenu = initlizeOptionsMenu();
Menu psMenu = initlizePlaySettingsMenu();

// Update Switch
void updateGame(sf::RenderWindow &window)
{
    switch (current_screen)
    {
    case 0:
        mainUpdate(mainMenu, current_screen, window);
        break;
    case 1:
        playSettingsUpdate(window, psMenu);
        break;
    case 2:
        gamePlayUpdate(window);
        break;
    case 3:
        optionsUpdate(window, opMenu);
        break;
    case 4:
        soundUpdate(window);
        break;

    case 5:
        numberOfPlayersUpdate(window);
        break;

    default:
        break;
    }
}

// Draw Switch
void drawGame(sf::RenderWindow &window)
{
    switch (current_screen)
    {
    case 0:
        mainDraw(mainMenu, window);
        break;
    case 1:
        playSettingsDraw(window, psMenu);
        break;
    case 2:
        gamePlayDraw(window);
        break;
    case 3:
        optionsDraw(window, opMenu);
        break;
    case 4:
        soundDraw(window);
        break;
    case 5:
        numberOfPlayersDraw(window);
        break;

    default:
        break;
    }
}