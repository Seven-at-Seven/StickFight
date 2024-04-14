#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

int curmap  = 0;
void gamePlayDraw(sf::RenderWindow &window);
void gamePlayUpdate(sf::RenderWindow &window);
struct blocks
{
    const float x_coordinate, y_coordinate,width,height;
};
struct maps
{
    const int num_of_blocks;
    blocks block[num_of_blocks];
    sf::Texture background;
};
maps map[6];

#endif // GAMEPLAY_H