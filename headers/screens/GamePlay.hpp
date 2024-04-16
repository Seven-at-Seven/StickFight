#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "components/Character.hpp"

void gamePlayUpdate(sf::RenderWindow &window, Character &character);
void gamePlayDraw(sf::RenderWindow &window, Character &character);

struct Blocks
{
    float x_coordinate = 0, y_coordinate = 0, width = 0, height = 0;
    sf::Sprite block_sprite;
    sf::Texture block_shape;
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
#endif // GAMEPLAY_H