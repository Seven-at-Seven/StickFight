#ifndef S_GLOBALS_H
#define S_GLOBALS_H
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "Map_utility.hpp"

#define JUMP -22

const float SCREENWIDTH = 1240.f;
const float SCREENHEIGHT = 480.f;
const sf::Vector2f GRAVITY = sf::Vector2f(0, 2.8);

extern sf::Vector2f VELOCITY[]; // = sf::Vector2f(0, 0);

extern int current_screen;
extern int last_screen;
extern int number_of_players;
extern sf::Event event;
extern int curmap;
extern Map map[6];

#endif // S_GLOBALS_H
