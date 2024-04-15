#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include "screens/MainMenu.hpp"     // Page 0
#include "screens/PlaySettings.hpp" // Page 1
#include "screens/GamePlay.hpp"     // Page 2
#include "screens/Options.hpp"      // Page 3

// Global states
int current_screen = 0;
sf::Vector2f VELOCITY = sf::Vector2f(0, 0);
sf::Event event;

// Menus
Menu mainMenu = initlizeMainMenu();
Menu opMenu = initlizeOptionsMenu();
Menu psMenu = initlizePlaySettingsMenu();

// create a main character instance
Character mainCharacter = initializeCharacter(50, 50, 100, 100, sf::Color::Green);

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
    default:
        break;
    }
}
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

    default:
        break;
    }
}