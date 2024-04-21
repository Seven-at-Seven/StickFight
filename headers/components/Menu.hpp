#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include "Globals.hpp"

#define MAX_NUMBER_OF_ITEMS 6

struct Menu
{
    float width, height;
    int selectedItem;
    int numberOfItems;
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
};

void moveSelectionUp(Menu &menu);
void moveSelectionDown(Menu &menu);
void drawMenu(Menu &menu, sf::RenderWindow &window, char *title);
void updateMenu(Menu &menu, sf::Event &event);
void loadMenuAssets();
Menu initlizeMenu(int numebrOfItems, char **items);

extern sf::Texture mainMenuBackgroundTexture;
extern sf::Sprite mainMenuBackgroundSprite;
#endif
