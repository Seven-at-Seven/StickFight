#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>
#include <string>

#define MAX_STONES 40

extern sf::Texture blocksTexture;

struct Block
{
    sf::Vector2f position, stone_size;
    int stone_num, rows;
    sf::Sprite blockSprites[MAX_STONES];
};

void drawBlock(sf::RenderWindow &winodw, Block &block);
Block initialize_block(sf::Vector2f position, int numStones, int rows);

#endif