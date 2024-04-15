#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "components/Character.hpp"

void gamePlayUpdate(sf::RenderWindow &window, Character &character);
void gamePlayDraw(sf::RenderWindow &window, Character &character);

#endif // GAMEPLAY_H