#ifndef Colors_H
#define Colors_H
#include <SFML/Graphics.hpp>
#include "components/Menu.hpp"

void colorsDraw(sf::RenderWindow &window, Menu &Menu);
void colorsUpdate(sf::RenderWindow &window, Menu &Menu);
void loadColorsAssets();
Menu initlizeColorsMenu();
#endif // GAMEPLAY_H