#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H
#include <SFML/Graphics.hpp>

#define DEFAULT_HP 100

struct HealthBar
{
    sf::Color color;
    int currentHP;
    sf::RectangleShape healthRectangle;
};
void loadHealthBarAssets();
void drawHealthBar(sf::RenderWindow &window);

#endif