#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

int curmap  = 0;
void gamePlayDraw(sf::RenderWindow &window);
void gamePlayUpdate(sf::RenderWindow &window);
struct blocks
{
    const float x_coordinate = 0, y_coordinate = 0,width = 0,height = 0;
};
struct mapss
{
    constexpr int num_of_blocks;
    blocks block[9];
    sf::Texture background;
};
mapss map1[6];

#endif // GAMEPLAY_H