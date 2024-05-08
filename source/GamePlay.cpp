#include "screens/GamePlay.hpp"
#include "Globals.hpp"
#include "components/Character.hpp"
#include "MapUtility.hpp"
#include "components/HealthBar.hpp"
#include "components/Weapons.hpp"
#include "screens/GameOver.hpp"
#include <iostream>

int current_map = 0;
int alive_counter = number_of_players;
int round_over_timer = 30;
int roundWinnerIndex = 0;
int gameWinnerIndex = 0;
bool gameOver = false;

// spawn characters/weapons in the new map,
// and refill the health bar for all damaged/dead characters
void startNewRound()
{
    spawnCharacters();
    restartWeapons();
}

void loadGamePlayAssets()
{
    // initialize
    startNewRound();
    // load assets
    loadCharacterAssets();
    loadMapAssets();
    loadHealthBarAssets();
    loadWeaponsAssets();
    loadBulletsAssets();
}
void handleRoundOver()
{

    if (round_over_timer == 0)
    {
        charactersArray[roundWinnerIndex].score++;
        round_over_timer = 30;

        // handle last round over
        if (current_map == 3)
        {
            // find the winner
            for (int i = 0; i < number_of_players; i++)
            {
                int gameWinnerScore = charactersArray[gameWinnerIndex].score;
                gameWinnerIndex = charactersArray[i].score > gameWinnerScore ? i : gameWinnerIndex;
            }
            // Stop the updateGamePlay loop and show GameOver screen
            gameOver = true;
        }
        // handle normal round over
        else
        {
            current_map++;
            startNewRound();
        }
    }
    else
        round_over_timer--;
}

void gamePlayUpdate(sf::RenderWindow &window)
{
    if (!gameOver)
    {

        alive_counter = number_of_players;
        for (int i = 0; i < number_of_players; i++)
        {
            if (charactersArray[i].isDead)
                alive_counter--;
            else
                roundWinnerIndex = i;
        }

        if (alive_counter <= 1)
            handleRoundOver();

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {

                    current_screen = last_screen;
                    last_screen = 0;
                }
            }

            handelCharacterEvents(event);

            // if (event.type == sf::Event::MouseButtonPressed)
            // {
            //     std::cout << "x is :" << event.mouseButton.x << std::endl;
            //     std::cout << "y is :" << event.mouseButton.y << std::endl;
            // }
        }
        updateCharacters();
        updateWeapons();
        updateBullets();
    }
    else
        updateGameOverScreen(window, gameWinnerIndex);
}

void gamePlayDraw(sf::RenderWindow &window)
{

    drawMap(window);
    drawCharacters(window);
    drawHealthBar(window);
    drawWeapons(window);
    drawBullets(window);
    if (gameOver)
        drawGameOverScreen(window);
}
