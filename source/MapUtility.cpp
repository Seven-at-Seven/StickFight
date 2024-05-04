#include "MapUtility.hpp"
#include <iostream>
#include "Configurations.hpp"
#include "components/Character.hpp"
#include "components/Weapons.hpp"
#include "components/Block.hpp"
#include "Globals.hpp"
#include <string>

Map map[4];
bool spawnNewMap[4] = {};

int abs(int x)
{
    x = x < 0 ? x * -1 : x;
    return x;
}
void loadMapAssets()
{

    loadBlockAssests();
    for (int i = 0; i < 4; i++)
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

    map[0].num_of_blocks = 5;
    auto map0Position0 = sf::Vector2f(20, 400);
    auto map0Position1 = sf::Vector2f(350, 400);
    auto map0Position2 = sf::Vector2f(700, 400);
    auto map0Position3 = sf::Vector2f(1050, 400);
    map[0].blocks[0] = initialize_block(map0Position0, 10, 3);
    map[0].blocks[1] = initialize_block(map0Position1, 10, 3);
    map[0].blocks[2] = initialize_block(map0Position2, 10, 3);
    map[0].blocks[3] = initialize_block(map0Position3, 10, 3);

    map[1].num_of_blocks = 5;
    for (int i = 0; i < map[1].num_of_blocks; i++)
    {
        auto x = (STONE_SIZE * 14) * i + 10;
        auto y = SCREENHEIGHT - MAX_JUMP_Y_AXIS * (-1 * abs(i - 2) + 3);

        map[1].blocks[i] = initialize_block(sf::Vector2f(x, y), 14, 2);
    }

    map[2].num_of_blocks = 3;
    map[2].blocks[0] = initialize_block(sf::Vector2f(0, 400), 20, 50);
    map[2].blocks[1] = initialize_block(sf::Vector2f(SCREENWIDTH - 360, 400), 20, 50);
    map[2].blocks[2] = initialize_block(sf::Vector2f(SCREENWIDTH / 2, 400), 2, 2);

    map[3].num_of_blocks = 1;
    map[3].blocks[0] = initialize_block(sf::Vector2f(0, 400), 69, 50);
}
void drawMap(sf::RenderWindow &window)
{
    // background
    window.draw(map[current_map].background_sprite);
    // stones
    for (int i = 0; i < map[current_map].num_of_blocks; i++)
    {
        drawBlock(window, map[current_map].blocks[i]);
    }
}