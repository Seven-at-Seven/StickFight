#ifndef PLYASETTINGS_H
#define PLYASETTINGS_H
#include <SFML/Graphics.hpp>
#include "components/Menu.hpp"

void playSettingsDraw(sf::RenderWindow &window, Menu &psMenu);
void playSettingsUpdate(sf::RenderWindow &window, Menu &psManu);
Menu initlizePlaySettingsMenu();
#endif // PLYASETTINGS_H