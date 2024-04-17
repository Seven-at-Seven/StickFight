#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "components/Block.hpp"

#define MAX_BLOCKS 6

struct Map
{
    int num_of_blocks;
    Block blocks[MAX_BLOCKS];
    sf::Texture background;
    sf::Sprite background_sprite;
    float xdir, ydir;
};
// functions
void loadingmap();
void loadMapBlocks(int mapIndex);
void drawMap(sf::RenderWindow &window, Map &map);
#endif