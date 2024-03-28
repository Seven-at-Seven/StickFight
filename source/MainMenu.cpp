#include "../headers/screens/MainMenu.hpp"
#include "../headers/Globals.hpp"

void mainUpdate()
{
}

void mainDraw(sf::RenderWindow &window)
{
    sf::RectangleShape myShape = sf::RectangleShape(sf::Vector2f(12.f, 12.f));
    myShape.setFillColor(sf::Color(255, 200, 255));
    window.draw(myShape);
}