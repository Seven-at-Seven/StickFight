#include"Map_utility.hpp"
#include "Globals.hpp"

maps map[6];
void declaringmap()
{
    map[0].background.loadFromFile("assets/images/forest.jpg");
    // map[0].block[0].block_texture.loadFromFile("assets/images/Mine_Blocks.png");
    // map[0].block[0].block_sprite.setTexture(map[0].block[0].block_texture);
    // map[0].block[0].block_sprite.setScale(0.15f,0.15f);
    map[1].background.loadFromFile("assets/images/background1.jpg");
    map[2].background.loadFromFile("assets/images/background2.png");
    map[3].background.loadFromFile("assets/images/background3.png");
    map[4].background.loadFromFile("assets/images/background4.png");
    map[5].background.loadFromFile("assets/images/background5.png");
    for (int i = 0; i < 6; i++)
    {
        map[i].background_sprite.setTexture(map[i].background);
        map[i].xdir = SCREENWIDTH / map[i].background_sprite.getGlobalBounds().width;
        map[i].ydir = SCREENHEIGHT / map[i].background_sprite.getGlobalBounds().height;
        map[i].background_sprite.setScale(sf::Vector2f(map[i].xdir, map[i].ydir));
    }
}