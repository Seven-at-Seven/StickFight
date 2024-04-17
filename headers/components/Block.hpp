#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>
#include <string>

#define MAX_NUMBER_OF_ITEMS 6
#define MAX_STONES 20

struct Stone
{
    float x_coordinate, y_coordinate;
    sf::Sprite stone_sprite;
    sf::Texture stone_texture;
};
struct Block
{
    sf::Vector2f position, stone_size;
    int stone_num, rows;
    Stone stones[MAX_STONES];
    char *block_texture;
};

void drawBlock(sf::RenderWindow &winodw, Block &block);
Block initialize_block(sf::Vector2f position, sf::Vector2f stoneSize, int numStones, int rows);

#endif