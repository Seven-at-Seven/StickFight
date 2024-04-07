#ifndef OPTIONS_H
#define OPTIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "components/Menu.hpp"

void optionsDraw(sf::RenderWindow &window, Menu &opMenu);
void optionsUpdate(sf::RenderWindow &window, Menu &opMenu);
Menu initlizeOptionsMenu();
#endif // OPTIONS_H