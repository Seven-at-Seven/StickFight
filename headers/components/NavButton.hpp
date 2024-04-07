#ifndef NAVBUTTON_H
#define NAVBUTTON_H
#include <SFML/Graphics.hpp>
#include <Globals.hpp>

struct NavButton
{
    sf::Vector2f position;
    sf::Vector2f size;
    char *text;
    sf::Font font;
    sf::RectangleShape buttonRec;
};

NavButton initNavButton(sf::Vector2f position, sf::Vector2f size, char *text);
void drawNavButton(sf::RenderWindow &window, NavButton &navButton);

#endif