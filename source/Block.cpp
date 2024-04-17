#include "components/Block.hpp"
#include <iostream>

void drawBlock(sf::RenderWindow &winodw, Block &block)
{
    for (int i = 0; i < block.rows; i++)
    {
        for (int j = 0; j < block.stone_num / block.rows; j++)
        {

            block.stones[i].stone_texture.loadFromFile(block.block_texture);
            block.stones[i].stone_sprite.setTexture(block.stones[i].stone_texture);
            block.stones[i].stone_sprite.setPosition(block.position.x + j * block.stone_size.x,
                                                     block.position.y + i * block.stone_size.y);
            block.stones[i].stone_sprite.setTextureRect(sf::IntRect(4 * 18, 0, 18, 18));
            block.stones[i].stone_sprite.setScale(sf::Vector2f(2.0f, 2.0f));
            winodw.draw(block.stones[i].stone_sprite);
        }
    }
}
Block initialize_block(sf::Vector2f position, sf::Vector2f stoneSize, int numStones, int rows)
{

    Block block;

    block.position = position;
    block.stone_num = numStones;
    block.rows = rows;
    block.stone_size = stoneSize;
    block.block_texture = "assets/images/blocks.png";
    return block;
}