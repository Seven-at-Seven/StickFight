#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Configurations.hpp"
#include <string.h>

#define JUMP -20

// Textures
#define IDLE_TEXTURE "assets/StickmanPack/Idle/thickIdleSheet.png"
#define PUNCH_TEXTURE "assets/StickmanPack/Punch/thickPunchSheet.png"
#define MOVEING_TEXTURE "assets/StickmanPack/Run/thickRunSheet.png"
#define HAVING_GUN_TEXTURE "assets/StickmanPack/Punch/HavingAGun.png"

struct Character
{
  std::string name;
  sf::Sprite sprite;
  sf::Color color;
  sf::RectangleShape area;

  int selectedIndex;

  int score;

  short texturesLimt = 6;
  short frames = 0;
  bool onGround = false;
  bool isDead = false;
  bool isMoving = false;
  bool isMovingLeft = false;
  bool isMovingRight = false;
  bool shallJump = false;
  bool isPunshing = false;
  bool isFiring = false;
  bool isOnBlock = false;
  bool isFacingLeft = false;
  bool isHavingGun = false;
  bool isFlying = false;
  bool isDamaged;
  int damageQuantity;
  sf::Vector2f playerVelocity = {};
};

void checkScreenCollision(Character &player);
void checkBlockCollision(Character &player);
bool checkPlayerHitCollision(Character &player);
void handlePlayerHitted(Character &player, int playerIndex);

void handelCharacterEvents(sf::Event &event);

void updatePlayerAnimation(Character &player);

void updateCharacters();
void drawCharacters(sf::RenderWindow &window);

void spawnCharacters();
void loadCharacterAssets();

void move(Character &player);

#endif // CHARACTER_H