#ifndef CONFIG_H
#define CONFIG_H
#include <SFML/Graphics.hpp>

// Game Configuration
#define MAX_PLAYERS_NUMBER 4
#define MAX_WEAPONS_NUMBER 4
#define PLAYER_SPEED 12
const float SCREENWIDTH = 1240.f;
const float SCREENHEIGHT = 480.f;
const sf::Vector2f GRAVITY = sf::Vector2f(0, 1.8);

#endif // CONFIG_H