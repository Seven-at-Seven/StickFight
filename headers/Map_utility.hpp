#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>

struct Blocks
{
    float x_coordinate, y_coordinate, width, height;
    sf::Sprite block_sprite;
    sf::Texture block_texture;
    sf::RectangleShape block_shape;
};
struct maps
{
    int num_of_blocks;
    Blocks block[6];
    sf::Texture background;
    sf::Sprite background_sprite;
    float xdir, ydir;
};
// functions

void declaringmap();
#endif