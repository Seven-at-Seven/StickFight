#include <SFML/Graphics.hpp>
#include "screens/GameOver.hpp"
#include "screens/GamePlay.hpp"
#include "components/Character.hpp"
#include "Globals.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

sf::RectangleShape darkBar;

sf::Font GameOverFont;
sf::Text GameOverMessages[MAX_GAMEOVER_MESSAGES];

sf::Text GameOverButtons[MAX_GAMEOVER_BUTTONS];

bool firstGameOverLoop = true;
bool leftChoiceIsSelected = true;

std::ofstream writeScore;
std::ifstream readScore;

void loadGameOverAssets(int winnerIndex)
{
    auto color = charactersArray[winnerIndex].color;

    if (!GameOverFont.loadFromFile("assets/VCR_OSD_MONO.ttf"))
    {

        std::cout << "error loading Game over font" << std::endl;
    }

    // Game Over messages
    {

        for (int i = 0; i < MAX_GAMEOVER_MESSAGES; i++)
        {
            GameOverMessages[i].setFont(GameOverFont);
            GameOverMessages[i].setCharacterSize(40);
            GameOverMessages[i].setFillColor(color);
        }
        GameOverMessages[0].setCharacterSize(80);

        GameOverMessages[0].setString("Game Over");
        auto GameOverMessageBounds = GameOverMessages[0].getGlobalBounds();
        GameOverMessages[0].setOrigin(sf::Vector2f(GameOverMessageBounds.width / 2, GameOverMessageBounds.height / 2));
        GameOverMessages[0].setPosition(sf::Vector2f(SCREENWIDTH / 2, 153 + 5 + GameOverMessageBounds.height / 2));

        GameOverMessages[1].setString("Winner is " + charactersArray[winnerIndex].name);
        GameOverMessageBounds = GameOverMessages[1].getGlobalBounds();
        GameOverMessages[1].setOrigin(sf::Vector2f(GameOverMessageBounds.width / 2, GameOverMessageBounds.height / 2));
        GameOverMessages[1].setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2));

        GameOverMessages[2].setString("Score is " + std::to_string(charactersArray[winnerIndex].score));
        GameOverMessageBounds = GameOverMessages[2].getGlobalBounds();
        GameOverMessages[2].setOrigin(sf::Vector2f(GameOverMessageBounds.width / 2, GameOverMessageBounds.height / 2));
        GameOverMessages[2].setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2 + 60));
    }

    // Game Over Buttons
    {

        GameOverButtons[0].setFont(GameOverFont);
        GameOverButtons[0].setCharacterSize(40);
        GameOverButtons[0].setString("Play again");
        GameOverButtons[0].setPosition(sf::Vector2f(SCREENWIDTH / 2 - 200, 153 + 400 - 60));

        GameOverButtons[1].setFont(GameOverFont);
        GameOverButtons[1].setCharacterSize(40);
        GameOverButtons[1].setString("Main Menu");
        GameOverButtons[1].setPosition(sf::Vector2f(SCREENWIDTH / 2 + 100, 153 + 400 - 60));
    }

    // Game Over Dark Bar
    {
        darkBar.setFillColor(sf::Color(0, 0, 0, 170));
        darkBar.setPosition(sf::Vector2f(0, 153));
        darkBar.setSize(sf::Vector2f(SCREENWIDTH, 400));
    }
}
void updateGameOverScreen(sf::RenderWindow &window, int winnerIndex)
{

    if (firstGameOverLoop)
    {
        readScore.open("score.txt");
        writeScore.open("score.txt", std::ios::app);
        std::string lines;

        writeScore << charactersArray[winnerIndex].name << " is the winner with score: " << charactersArray[winnerIndex].score << "\n";
        writeScore.close();
        firstGameOverLoop = false;
        loadGameOverAssets(winnerIndex);
    }
    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right ||
                event.key.code == sf::Keyboard::Left)
            {
                leftChoiceIsSelected = !leftChoiceIsSelected;
            }
            if (event.key.code == sf::Keyboard::Enter)
            {
                current_map = 0;
                gameOver = false;
                firstGameOverLoop = true;
                startNewRound();
                for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
                {
                    charactersArray[i].score = 0;
                    charactersArray[i].score = 0;
                    if (!leftChoiceIsSelected)
                        charactersArray[i].name = "";
                }
                if (!leftChoiceIsSelected)
                {
                    current_screen = 0;
                }
            }
        }
    }
}
void drawGameOverScreen(sf::RenderWindow &window)
{
    window.draw(darkBar);
    for (int i = 0; i < MAX_GAMEOVER_MESSAGES; i++)
    {
        window.draw(GameOverMessages[i]);
    }
    for (int i = MAX_GAMEOVER_BUTTONS - 1; i >= 0; i--)
    {
        if (i != leftChoiceIsSelected)
            GameOverButtons[i].setFillColor(sf::Color(255, 255, 255));
        else
            GameOverButtons[i].setFillColor(sf::Color(255, 255, 255, 100));

        window.draw(GameOverButtons[i]);
    }
}