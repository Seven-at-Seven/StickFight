#ifndef Sound_H
#define Sound_H
#include <SFML/Graphics.hpp>
#include <components/Menu.hpp>

void soundDraw(sf::RenderWindow &window, Menu &SoundMenu);
void soundUpdate(sf::RenderWindow &window, Menu &SoundMenu);

Menu initlizeSoundMenu();
void loadSoundAssets();
#endif // GAMEPLAY_H