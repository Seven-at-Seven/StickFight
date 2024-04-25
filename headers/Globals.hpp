#ifndef S_GLOBALS_H
#define S_GLOBALS_H
#include <SFML/Graphics.hpp>
#include "MapUtility.hpp"
#include "components/Character.hpp"
#include "Configurations.hpp"
#include "components/HealthBar.hpp"
#include "components/Weapons.hpp"

// Global Variables
extern Character charactersArray[MAX_PLAYERS_NUMBER];
extern HealthBar healthBarArray[MAX_PLAYERS_NUMBER];
extern Weapon weaponArray[MAX_WEAPONS_NUMBER];

extern sf::Texture blocksTexture;
extern sf::Color palyersColors[];
extern sf::Event event;

extern int number_of_players;
extern int current_screen;
extern int last_screen;
extern int current_map;

extern Map map[6];

// Global Character states
extern bool isHavingGun[MAX_PLAYERS_NUMBER];
extern sf::Vector2f playerVelocity[MAX_PLAYERS_NUMBER];

#endif // S_GLOBALS_H
