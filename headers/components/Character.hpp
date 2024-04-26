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

struct Damage
{
  bool yes;
  int damageQuantity;
};

struct Character
{
  sf::Sprite sprite;
  int selectedIndex;
  sf::Color color;
  sf::RectangleShape area;

  short texturesLimt = 6;
  short frames = 0;
  bool onGround = false;
  bool isMoving = false;
  bool isPunshing = false;
  bool isOnBlock = false;
  bool isFacingLeft = false;
  bool isHavingGun = false;
  bool isFlying = false;
  Damage isDamaged = {};
  sf::Vector2f playerVelocity = {};
};

void checkScreenCollision(Character &player);
void checkBlockCollision(Character &player);
void move(Character &player);
void handelCharacterEvents(sf::Event &event);
void charactersUpdate(sf::RenderWindow &window);
void charactersDraw(sf::RenderWindow &window);
void loadCharacterAssets();

#endif // CHARACTER_H