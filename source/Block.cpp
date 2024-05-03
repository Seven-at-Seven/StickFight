#include "components/Block.hpp"
#include "Globals.hpp"
#include <iostream>

sf::Texture stoneTexture;
sf::Texture stoneTopTexture;
void loadBlockAssests()
{
    if (!stoneTexture.loadFromFile(STONE_TEXTURE))
    {
        std::cout << "Error loading map assets" << std::endl;
    }
    if (!stoneTopTexture.loadFromFile(STONE_TOP_TEXTURE))
    {
        std::cout << "Error loading map assets" << std::endl;
    }
    else
        std::cout << "Loading map assets" << std::endl;
}

void drawBlock(sf::RenderWindow &winodw, Block &block)
{
    for (int i = 0; i < block.rows; i++)
    {
        for (int j = 0; j < block.columns; j++)
        {
            sf::Vector2f currentStonePosition = sf::Vector2f(block.position.x + j * STONE_SIZE,
                                                             block.position.y + i * STONE_SIZE);
            block.stones[i].setPosition(currentStonePosition);
            block.stones[i].setTextureRect(sf::IntRect(0, 0, 18, 18));
            if (i == 0)
                block.stones[i].setTexture(stoneTopTexture);

            else
                block.stones[i].setTexture(stoneTexture);

            winodw.draw(block.stones[i]);
        }
    }
}
Block initialize_block(sf::Vector2f position, int columns, int rows)
{

    Block block;

    block.position = position;
    block.columns = columns;
    block.rows = rows;
    block.block_area.setSize(sf::Vector2f((STONE_SIZE * columns), STONE_SIZE * rows));
    block.block_area.setPosition(sf::Vector2f(position.x, position.y));
    block.block_area.setFillColor(sf::Color::Green);
    return block;
}