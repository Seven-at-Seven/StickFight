#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Configurations.hpp"

#define JUMP -22

// Textures
#define IDLE_TEXTURE "assets/StickmanPack/Idle/thickIdleSheet.png"
#define PUNCH_TEXTURE "assets/StickmanPack/Punch/thickPunchSheet.png"
#define MOVEING_TEXTURE "assets/StickmanPack/Run/thickRunSheet.png"
#define HAVING_GUN_TEXTURE "assets/StickmanPack/Punch/HavingAGun.png"

struct Character
{
  sf::Sprite sprite;
  int selectedIndex;
  sf::Color color;
  sf::RectangleShape area;
};

void checkScreenCollision(Character &player, int playerIndex);
void checkBlockCollision(Character &player, int current_map);
void move(Character &player, sf::Vector2f offset);
void handelCharacterEvents(sf::Event &event);
void charactersUpdate(sf::RenderWindow &window);
void charactersDraw(sf::RenderWindow &window);
void loadCharacterAssets();

#endif // CHARACTER_H