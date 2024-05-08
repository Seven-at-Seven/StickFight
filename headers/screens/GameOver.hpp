#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>

#define MAX_GAMEOVER_MESSAGES 3
#define MAX_GAMEOVER_BUTTONS 3

void loadGameOverAssets(int winnerIndex);
void drawGameOverScreen(sf::RenderWindow &window);
void updateGameOverScreen(sf::RenderWindow &window, int winnerIndex);

#endif // GAMEOVER_H