#ifndef CHARACTER_H
#define CHARACTER_H
#include "Globals.hpp"

#define IDLE_TEXTURE "assets/StickmanPack/Idle/thickIdleSheet.png"
#define PUNCH_TEXTURE "assets/StickmanPack/Punch/thickPunchSheet.png"
#define MOVEING_TEXTURE "assets/StickmanPack/Run/thickRunSheet.png"
#define HAVING_GUN_TEXTURE "assets/StickmanPack/Punch/HavingAGun.png"
#define JUMP -22

extern sf::Texture CharacterTextures[4];

struct Character
{
  sf::Sprite sprite;
  int selectedIndex;
  float width, height, posX, posY;
  sf::Color color;
};

extern Character charactersArray[4];
void checkScreenCollision(Character &player, sf::RenderWindow &window);
void move(Character &player, sf::Vector2f offset);
void handelCharacterEvents(sf::Event &event);
void charactersUpdate(sf::RenderWindow &window);
void charactersDraw(sf::RenderWindow &window);
void loadCharacterAssets();

#endif // CHARACTER_H