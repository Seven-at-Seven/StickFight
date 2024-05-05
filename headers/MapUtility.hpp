#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>

#include "components/Block.hpp"

#define MAX_BLOCKS 9
#define MAX_JUMP_Y_AXIS 84
#define MAX_JUMP_X_AXIS 78

struct Map
{
    int num_of_blocks;
    Block blocks[MAX_BLOCKS];
    sf::Texture background;
    sf::Sprite background_sprite;
};
// functions
void loadMapAssets();
void loadMapBlocks();
void drawMap(sf::RenderWindow &window);
#endif