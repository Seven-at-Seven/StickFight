#ifndef PLYASETTINGS_H
#define PLYASETTINGS_H
#include <SFML/Graphics.hpp>
#include "components/Menu.hpp"

void playSettingsDraw(sf::RenderWindow &window, Menu &psMenu);
void playSettingsUpdate(sf::RenderWindow &window, Menu &psManu);
void numberOfPlayersUpdate(sf::RenderWindow &window);
void numberOfPlayersDraw(sf::RenderWindow &window);
Menu initlizePlaySettingsMenu();
Menu initlizeNumberOfPlayersMenu();
#endif // PLYASETTINGS_H