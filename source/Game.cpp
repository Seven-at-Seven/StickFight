#include <SFML/Graphics.hpp>
#include <../headers/Game.hpp>
#include "../headers/screens/MainMenu.hpp"     // Page 0
#include "../headers/screens/PlaySettings.hpp" // Page 1
#include "../headers/screens/GamePlay.hpp"     // Page 2
#include "../headers/screens/Options.hpp"      // Page 3

int current_screen = 0;
Menu menu = initlizeMainMenu();

void updateGame(sf::RenderWindow &window)
{
    switch (current_screen)
    {
    case 0:
        mainUpdate(menu, current_screen, window);
        break;
    case 1:
        playSettingsUpdate();
        break;
    case 2:
        gamePlayUpdate();
        break;
    case 3:
        optionsUpdate();
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
        mainDraw(menu, window);
        break;
    case 1:
        playSettingsDraw(window);
        break;
    case 2:
        gamePlayDraw(window);
        break;
    case 3:
        optionsDraw(window);
        break;

    default:
        break;
    }
}