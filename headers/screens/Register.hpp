#ifndef NAMES_H
#define NAMES_H
#include <SFML/Graphics.hpp>
#include "Configurations.hpp"
#include <string>
#include "Globals.hpp"
#include <iostream>

void registerDraw(sf::RenderWindow &window);
void registerUpdate(sf::RenderWindow &window);
void loadRegisterAssets();

void drawColors(sf::RenderWindow &window);
void updateColors();

void drawNames(sf::RenderWindow &window);
void updateNames();
#endif