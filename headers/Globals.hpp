#ifndef S_GLOBALS_H
#define S_GLOBALS_H
#include <SFML/Graphics.hpp>
#include "MapUtility.hpp"
#include "components/Character.hpp"
#include "Configurations.hpp"
#include "components/HealthBar.hpp"

// Global Variables
extern Character charactersArray[MAX_PLAYERS_NUMBER];
extern HealthBar healthBarArray[MAX_PLAYERS_NUMBER];
extern sf::Texture blocksTexture;
extern sf::Color palyersColors[];
extern int number_of_players;
extern int current_screen;
extern sf::Event event;
extern int last_screen;
extern int current_map;
extern Map map[6];

#endif // S_GLOBALS_H
