#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "components/Character.hpp"

void loadGamePlayAssets();
void gamePlayUpdate(sf::RenderWindow &window);
void gamePlayDraw(sf::RenderWindow &window);

#endif // GAMEPLAY_H