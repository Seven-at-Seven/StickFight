#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "MapUtility.hpp"
#include "components/HealthBar.hpp"
#include "screens/MainMenu.hpp"                   // Screen 0
#include "screens/PlaySettings.hpp"               // Screen 1
#include "screens/GamePlay.hpp"                   // Screen 2
#include "screens/Options.hpp"                    // Screen 3
#include "screens/Sound.hpp"                      // Screen 4
#include "screens/subscreens/NumberOfPlayers.hpp" // Screen 5
#include "screens/Register.hpp"                   // Screen 9
#include "components/Weapons.hpp"
#include "components/Bullets.hpp"

// Global states
int current_screen = 0;
int last_screen = 0;
int number_of_players = 2;
sf::Event event;

// Menus

Menu mainMenu = initlizeMainMenu();
Menu opMenu = initlizeOptionsMenu();
Menu psMenu = initlizePlaySettingsMenu();
Menu SoundMenu = initlizeSoundMenu();

void loadGameAssets()
{
    srand(time(nullptr));
    loadSoundAssets();
    loadMenuAssets();
    loadGamePlayAssets();
    loadRegisterAssets();
}

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
        soundUpdate(window, SoundMenu);
        break;
    case 5:
        numberOfPlayersUpdate(window);
        break;
    case 9:
        registerUpdate(window);
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
        soundDraw(window, SoundMenu);
        break;
    case 5:
        numberOfPlayersDraw(window);
        break;
    case 9:
        registerDraw(window);
        break;

    default:
        break;
    }
}
