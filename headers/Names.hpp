#ifndef NAMES_H
#define NAMES_H
#include <SFML/Graphics.hpp>
#include "Configurations.hpp"
#include <string>
#include "Globals.hpp"
#include <iostream>

void draw_name_screen(sf::RenderWindow &window);
void NamesDraw(sf::RenderWindow &window);
void NamesUpdate(sf::RenderWindow &window,std::string names[]);
#endif