#include "Map_utility.hpp"
#include "Globals.hpp"

Map map[6];
void loadingmap()
{
    // map[0].block[0].height = (float)SCREENHEIGHT / 7.1;
    // map[0].block[0].width = map[0].block[0].height * 3.9;
    // map[0].block[0].block_shape.setSize(sf::Vector2f(map[0].block[0].width, map[0].block[0].height));
    // map[0].block[0].block_shape.setOrigin(sf::Vector2f(map[0].block[0].originX, map[0].block[0].originY));
    // map[0].block[0].block_shape.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, SCREENHEIGHT / 2.0f));
    // map[0].block[0].block_texture.loadFromFile("assets/images/spaceblock.png");
    // map[0].block[0].block_shape.setTexture(&map[0].block[0].block_texture);
    for (int i = 0; i < 6; i++)
    {
     //   loadingblocks(i);
        map[i].background.loadFromFile("assets/images/background" + std::to_string(i) + ".png");
        map[i].background_sprite.setTexture(map[i].background);

        // Get the scale factors required to fit the background to the screen size
        float scaleX = SCREENWIDTH / map[i].background_sprite.getLocalBounds().width;
        float scaleY = SCREENHEIGHT / map[i].background_sprite.getLocalBounds().height;

        // Apply the scale factors uniformly to avoid distortion
        map[i].background_sprite.setScale(sf::Vector2f(scaleX, scaleY));
    }
}
Block initialize_block(sf::Texture texture, sf::Vector2f position, int numstones, int rows)
{
    Block block;
    block.block_texture = texture;
    block.position = position;
    block.rows = rows;
    block.stone_num = numstones;
    return block;
}
// void loadingblocks(int mapindex)
// {
//     int x = map[mapindex].num_of_blocks;
//     for (int j = 0; j < x; j++)
//     {
//         map[mapindex].block[j] = initialize_block
//     }
// }