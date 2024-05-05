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

    // map[0]has 8 blocks

    map[0].num_of_blocks = 8;
    auto map0Position0 = sf::Vector2f(468, 267);
    auto map0Position1 = sf::Vector2f(898, 279);
    auto map0Position2 = sf::Vector2f(110, 598);
    auto map0Position3 = sf::Vector2f(1031, 395);
    auto map0Position4 = sf::Vector2f(278, 491);
    auto map0Position5 = sf::Vector2f(145, 394);
    auto map0Position6 = sf::Vector2f(278, 280);
    auto map0Position7 = sf::Vector2f(898, 492);
    map[0].blocks[0] = initialize_block(map0Position0, 18, 4);
    map[0].blocks[1] = initialize_block(map0Position1, 4, 3);
    map[0].blocks[2] = initialize_block(map0Position2, 58, 4);
    map[0].blocks[3] = initialize_block(map0Position3, 4, 3);
    map[0].blocks[4] = initialize_block(map0Position4, 4, 3);
    map[0].blocks[5] = initialize_block(map0Position5, 4, 3);
    map[0].blocks[6] = initialize_block(map0Position6, 4, 3);
    map[0].blocks[7] = initialize_block(map0Position7, 4, 3);

    map[1].num_of_blocks = 4;
    map[1].blocks[0] = initialize_block(sf::Vector2f(SCREENWIDTH / 4.7, SCREENHEIGHT / 1.6), 4, 53);
    map[1].blocks[1] = initialize_block(sf::Vector2f(SCREENWIDTH / 2.59, SCREENHEIGHT / 1.6), 4, 53);
    map[1].blocks[2] = initialize_block(sf::Vector2f(SCREENWIDTH / 1.79, SCREENHEIGHT / 1.6), 4, 53);
    map[1].blocks[3] = initialize_block(sf::Vector2f(SCREENWIDTH / 1.37, SCREENHEIGHT / 1.6), 4, 53);


    map[2].num_of_blocks = 2;
    map[2].blocks[0] = initialize_block(sf::Vector2f(0, 576), 27, 7);
    map[2].blocks[1] = initialize_block(sf::Vector2f(SCREENWIDTH / 1.5, 576), 24, 7);

    map[3].num_of_blocks = 1;
    map[3].blocks[0] = initialize_block(sf::Vector2f(0, 418), 69, 20);
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