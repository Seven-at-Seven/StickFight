#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFML/Graphics.hpp>

#include "Globals.hpp"
#include "components/Menu.hpp"

void mainDraw(Menu &menu, sf::RenderWindow &window);
void mainUpdate(Menu &menu, int &current_screen, sf::RenderWindow &window);
Menu initlizeMainMenu();

#endif
