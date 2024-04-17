#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX_STONES 9
#define MAX_BLOCKS 6

struct Stone
{
    float x_coordinate, y_coordinate;
    sf::Sprite stone_sprite;
};

struct Block
{
    sf::Vector2f position, stone_size;
    int stone_num, rows;
    Stone stones[MAX_STONES];
    sf::Texture block_texture;
    // Calculate the center point
    // float originX = width / 2.0f;
    // float originY = height / 2.0f;
};
struct Map
{
    int num_of_blocks;
    Block blocks[MAX_BLOCKS];
    sf::Texture background;
    sf::Sprite background_sprite;
    float xdir, ydir;
};
// functions
Block initialize_block(sf::Texture texture, sf::Vector2f position, int numblocks, int rows);
void loadingmap();
void loadingblocks(int mapindex);
#endif