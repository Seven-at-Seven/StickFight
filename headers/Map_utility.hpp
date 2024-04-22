#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "components/Block.hpp"

#define MAX_BLOCKS 6
#define BLOCKS_TEXTURE_PATH "assets/images/blocks.png"
#define MAX_JUMP_Y_AXIS 84
#define MAX_JUMP_X_AXIS 78

struct Map
{
    int num_of_blocks;
    Block blocks[MAX_BLOCKS];
    sf::Texture background;
    sf::Sprite background_sprite;
    float xdir, ydir;
};
extern Map map[6];
// functions
void loadMapAssets();
void loadMapBlocks();
void drawMap(sf::RenderWindow &window, Map &map, int texture_row_index, int texture_col_index);
#endif