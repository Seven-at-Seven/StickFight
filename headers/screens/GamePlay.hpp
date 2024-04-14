#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

void gamePlayDraw(sf::RenderWindow &window);
void gamePlayUpdate(sf::RenderWindow &window);

struct blocks
{
    float x_coordinate = 0, y_coordinate = 0,width = 0,height = 0;
    sf::Texture block_shape;
};
struct maps
{
   int num_of_blocks;
    blocks block[9];
    sf::Texture background;
};

#endif // GAMEPLAY_H