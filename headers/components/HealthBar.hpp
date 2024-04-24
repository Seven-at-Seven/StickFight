#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H
#include <SFML/Graphics.hpp>

#define MAX_HEALTH_BARS_NUMBER 4
#define DEFAULT_HP 100

struct HealthBar
{
    sf::Color color;
    int currentHP;
};
void updateHealthBar();
void drawHealthBar();

#endif