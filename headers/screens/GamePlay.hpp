#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

void loadGamePlayAssets();
void startNewRound();

void gamePlayUpdate(sf::RenderWindow &window);
void gamePlayDraw(sf::RenderWindow &window);

#endif // GAMEPLAY_H