#ifndef BLOCKS_H
#define BLOCKS_H

#include <SFML/Graphics.hpp>

#define MAX_STONES 60
#define STONE_SIZE 18
#define STONE_TEXTURE "assets/images/stone.png"
#define STONE_TOP_TEXTURE "assets/images/stoneTop.png"

struct Block
{
    int columns, rows;

    sf::Vector2f position;
    sf::Sprite stones[MAX_STONES];
    sf::RectangleShape block_area;
};

void drawBlock(sf::RenderWindow &winodw, Block &block);
void loadBlockAssests();
Block initialize_block(sf::Vector2f position, int columns, int rows);

#endif