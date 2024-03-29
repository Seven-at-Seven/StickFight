#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include "Globals.hpp"

#define MAX_NUMBER_OF_ITEMS 3

struct Menu
{
    float width, height;
    int selectedItem;
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
};

void moveSelectionUp(Menu &menu);
void moveSelectionDown(Menu &menu);
void mainDraw(Menu &menu, sf::RenderWindow &window);
void mainUpdate(Menu &menu, int &current_screen, sf::RenderWindow &window);
Menu initlizeMainMenu();

#endif
