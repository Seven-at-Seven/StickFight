#include "MapUtility.hpp"
#include <iostream>
#include "Configurations.hpp"
#include <string>

Map map[6];
sf::Texture blocksTexture;

int abs(int x)
{
    x = x < 0 ? x * -1 : x;
    return x;
}
void loadMapAssets()
{
    if (!blocksTexture.loadFromFile(BLOCKS_TEXTURE_PATH))
    {
        std::cout << "Error loading map assets" << std::endl;
    }

    for (int i = 0; i < 6; i++)
    {
        map[i].background.loadFromFile("assets/images/background" + std::to_string(i) + ".png");
        map[i].background_sprite.setTexture(map[i].background);

        float scaleX = SCREENWIDTH / map[i].background_sprite.getLocalBounds().width;
        float scaleY = SCREENHEIGHT / map[i].background_sprite.getLocalBounds().height;

        map[i].background_sprite.setScale(sf::Vector2f(scaleX, scaleY));
    }
    loadMapBlocks();
}

void loadMapBlocks()
{

    // map[0]has 3 blocks

    map[0].num_of_blocks = 3; // The block position is based on the law of projectiles....but some positions only for a good shape
    map[0].blocks[0] = initialize_block(sf::Vector2f(SCREENWIDTH / 2 - (17 * STONE_SIZE) / 2, SCREENHEIGHT / 2 + 70), 34, 2);
    map[0].blocks[1] = initialize_block(sf::Vector2f((SCREENWIDTH / 2 - (17 * STONE_SIZE) / 2 - (4 * STONE_SIZE)) - MAX_JUMP_X_AXIS / 2 + 10,
                                                     SCREENHEIGHT / 2 + 70 - (MAX_JUMP_Y_AXIS - 10)),
                                        4, 1);
    map[0].blocks[2] = initialize_block(sf::Vector2f((SCREENWIDTH / 2 + (17 * STONE_SIZE) / 2) + MAX_JUMP_X_AXIS / 2 - 10,
                                                     SCREENHEIGHT / 2 + 70 - (MAX_JUMP_Y_AXIS - 10)),
                                        4, 1);

    // map[1] "map of prabola shape"

    map[1].num_of_blocks = 5;
    for (int i = 0; i < map[1].num_of_blocks; i++)
    {

        map[1].blocks[i] = initialize_block(sf::Vector2f((MAX_JUMP_X_AXIS / 2 + STONE_SIZE * 7) * i + 10,
                                                         SCREENHEIGHT - MAX_JUMP_Y_AXIS * (-1 * abs(i - 2) + 3)),
                                            14, 2);
    }

    // map[2] "map of straight blocks "
    map[2].num_of_blocks = 5;
    for (int i = 0; i < map[2].num_of_blocks; i++)
    {
        map[2].blocks[i] = initialize_block(sf::Vector2f(75 + i * 5 * STONE_SIZE + i * (MAX_JUMP_X_AXIS - 10),
                                                         SCREENHEIGHT - 200),
                                            10, 2);
    }

    // map[3]"map of up and down"
    map[3].num_of_blocks = 5;
    for (int i = 0; i < map[3].num_of_blocks; i++)
    {
        // the modulo is responsible for "up and down"
        map[3].blocks[i] = initialize_block(sf::Vector2f(140 + (i) * 5 * STONE_SIZE + i * (MAX_JUMP_X_AXIS / 2),
                                                         SCREENHEIGHT - 150 - (i % 2) * (MAX_JUMP_Y_AXIS)),
                                            10, 2);
    }
    map[4].num_of_blocks = 5;
}
void drawMap(sf::RenderWindow &window, Map &map, int texture_row_index = 4, int texture_col_index = 0)
{
    window.draw(map.background_sprite);
    for (int i = 0; i < map.num_of_blocks; i++)
    {
        drawBlock(window, map.blocks[i], texture_row_index, texture_col_index);
    }
}