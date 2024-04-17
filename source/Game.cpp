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
sf::Vector2f VELOCITY = sf::Vector2f(0, 0);
int last_screen = 0;
int number_of_players = 2;
sf::Event event;

// Menus

Menu mainMenu = initlizeMainMenu();
Menu opMenu = initlizeOptionsMenu();
Menu psMenu = initlizePlaySettingsMenu();
Menu SoundMenu = initlizeSoundMenu();

// create a main character instance
Character mainCharacter = initializeCharacter(64, 64, 100, 100, sf::Color::Green);

// Map

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
        gamePlayUpdate(window, mainCharacter);
        break;
    case 3:
        optionsUpdate(window, opMenu);
        break;
    case 4:
        soundUpdate(window, SoundMenu);
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
        gamePlayDraw(window, mainCharacter);
        break;
    case 3:
        optionsDraw(window, opMenu);
        break;
    case 4:
        soundDraw(window, SoundMenu);
        break;
    case 5:
        numberOfPlayersDraw(window);
        break;

    default:
        break;
    }
}