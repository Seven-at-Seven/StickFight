#include "components/Block.hpp"
#include <iostream>

sf::Texture blocksTexture;

void drawBlock(sf::RenderWindow &winodw, Block &block, int texture_row_index, int texture_col_index)
{
    int temp_texture_row_index = texture_row_index, temp_texture_col_index = texture_col_index;
    for (int i = 0; i < block.rows; i++)
    {
        for (int j = 0; j < block.stone_num / block.rows; j++)
        {

            block.blockSprites[i].setTexture(blocksTexture);
            block.blockSprites[i].setPosition(block.position.x + j * STONE_SIZE,
                                              block.position.y + i * STONE_SIZE);
            // Choosing the block from the image
            block.blockSprites[i].setTextureRect(sf::IntRect(temp_texture_row_index * 18,
                                                             temp_texture_col_index * 18, 18, 18));
            temp_texture_row_index++;
            if (temp_texture_row_index % 2 == 0 && temp_texture_row_index != texture_row_index)
                temp_texture_row_index = texture_row_index;
            block.blockSprites[i].setScale(sf::Vector2f(2.0f, 2.0f));
            winodw.draw(block.blockSprites[i]);
        }
        temp_texture_col_index++;
        if (temp_texture_col_index % 3 == 0 && temp_texture_col_index != texture_col_index)
            temp_texture_col_index = texture_col_index;
    }
}
Block initialize_block(sf::Vector2f position, int numStones, int rows)
{

    Block block;

    block.position = position;
    block.stone_num = numStones;
    block.rows = rows;
    block.block_area.setSize(sf::Vector2f(STONE_SIZE * (numStones / rows), STONE_SIZE * rows));
    block.block_area.setPosition(position);
    return block;
}