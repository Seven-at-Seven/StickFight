
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Globals.hpp"

struct Character
{
  sf::RectangleShape rect;
  float width, height, posX, posY;
  sf::Color color;
};

Character initializeCharacter(float width, float height, float posX, float posY, sf::Color color);
void checkScreenCollision(Character &player, sf::RenderWindow &window);
void move(Character &player, sf::Vector2f offset);

void handelCharacterEvents(Character &character, sf::Event &event);
void characterUpdate(sf::RenderWindow &window, Character &character, sf::Event &event);
void characterDraw(sf::RenderWindow &window, Character &character);

#endif // CHARACTER_H