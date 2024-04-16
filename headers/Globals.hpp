#ifndef S_GLOBALS_H
#define S_GLOBALS_H
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include"screens/GamePlay.hpp"
#include "Map_utility.hpp"

const int SCREENWIDTH = 1240;
const int SCREENHEIGHT = 480;

extern int current_screen;
extern int number_of_players;
extern sf::Event event;
extern int curmap;
extern maps map[6];

#endif // S_GLOBALS_H
