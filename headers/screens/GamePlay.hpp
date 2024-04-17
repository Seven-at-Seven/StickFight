#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "components/Character.hpp"

void gamePlayUpdate(sf::RenderWindow &window, Character &character);
void gamePlayDraw(sf::RenderWindow &window, Character &character);

// functions

void declaringmap();
void gamePlayDraw(sf::RenderWindow &window);
void gamePlayUpdate(sf::RenderWindow &window);
#endif // GAMEPLAY_H