#ifndef NUMBEROFPLYAERS_H
#define NUMBEROFPLYAERS_H

#include <SFML/Graphics.hpp>
#include "components/Menu.hpp"

void numberOfPlayersUpdate(sf::RenderWindow &window);
void numberOfPlayersDraw(sf::RenderWindow &window);

Menu initlizeNumberOfPlayersMenu();

#endif // NUMBEROFPLYAERS_H