#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>
#include <string>

#define MAX_STONES 60
#define STONE_SIZE 30

extern sf::Texture blocksTexture;

struct Block
{
    sf::Vector2f position, stone_size;
    int stone_num, rows;
    sf::Sprite blockSprites[MAX_STONES];
    sf::RectangleShape block_area;
};

void drawBlock(sf::RenderWindow &winodw, Block &block, int num_row_index = 4, int num_col_index = 0);
Block initialize_block(sf::Vector2f position, int numStones, int rows);

#endif