#include "components/Block.hpp"
#include <iostream>

sf::Texture blocksTexture;

void drawBlock(sf::RenderWindow &winodw, Block &block)
{
    for (int i = 0; i < block.rows; i++)
    {
        for (int j = 0; j < block.stone_num / block.rows; j++)
        {

            block.blockSprites[i].setTexture(blocksTexture);
            block.blockSprites[i].setPosition(block.position.x + j * block.stone_size.x,
                                              block.position.y + i * block.stone_size.y);
            block.blockSprites[i].setTextureRect(sf::IntRect(4 * 18, 0, 18, 18));
            block.blockSprites[i].setScale(sf::Vector2f(2.0f, 2.0f));
            winodw.draw(block.blockSprites[i]);
        }
    }
}
Block initialize_block(sf::Vector2f position, sf::Vector2f stoneSize, int numStones, int rows)
{

    Block block;

    block.position = position;
    block.stone_size = stoneSize;
    block.stone_num = numStones;
    block.rows = rows;

    return block;
}