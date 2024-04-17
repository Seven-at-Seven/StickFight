#include "Map_utility.hpp"
#include "Globals.hpp"

Map map[6];
void loadingmap()
{
    map[0].num_of_blocks = 1;
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
void loadMapBlocks(int mapIndex)
{
    if (mapIndex == 0)
    {
        map[0].blocks[0] = initialize_block(sf::Vector2f(200, SCREENHEIGHT - 2 * 40), sf::Vector2f(20, 20), 30, 2);
    }
}
void drawMap(sf::RenderWindow &window, Map &map)
{
    window.draw(map.background_sprite);
    for (int i = 0; i < map.num_of_blocks; i++)
    {
        drawBlock(window, map.blocks[i]);
    }
}