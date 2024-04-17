#ifndef CHARACTER_H
#define CHARACTER_H
#include "Globals.hpp"

#define IDLE_TEXTURE "assets/StickmanPack/Idle/thickIdleSheet.png"
#define PUNCH_TEXTURE "assets/StickmanPack/Punch/thickPunchSheet.png"
#define MOVEING_TEXTURE "assets/StickmanPack/Run/thickRunSheet.png"

extern sf::Texture CharacterTextures[3];

struct Character
{
  sf::Sprite sprite;
  int selectedIndex;
  float width, height, posX, posY;
  sf::Color color;
};

Character initializeCharacter(float width, float height, float posX, float posY, sf::Color color);
void checkScreenCollision(Character &player, sf::RenderWindow &window);
void move(Character &player, sf::Vector2f offset);
void handelCharacterEvents(Character &character, sf::Event &event);
void characterUpdate(sf::RenderWindow &window, Character &character,
                     Map &map);
void characterDraw(sf::RenderWindow &window, Character &character);
void loadCharacterAssets();

#endif // CHARACTER_H