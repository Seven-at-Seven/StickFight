#include "screens/Sound.hpp"
#include "Globals.hpp"
#include <iostream>

int current_sound_texture = 3;
sf::Texture soundSliderTextures[7];
sf::Sprite soundSliderSprite;

bool firstload = true;

void loadSoundAssets()
{

    if (!soundSliderTextures[0].loadFromFile("assets/images/sound/0.png"))
    {
        std::cout << "error on loading Sound photo" << std::endl;
    }
    if (!soundSliderTextures[1].loadFromFile("assets/images/sound/20.png"))
    {
        std::cout << "error on loading sound photo " << std::endl;
    }
    if (!soundSliderTextures[2].loadFromFile("assets/images/sound/40.png"))
    {
        std::cout << "error on loading sound photo " << std::endl;
    }
    if (!soundSliderTextures[3].loadFromFile("assets/images/sound/50.png"))
    {
        std::cout << "error on loading sound photo " << std::endl;
    }
    if (!soundSliderTextures[4].loadFromFile("assets/images/sound/60.png"))
    {
        std::cout << "error on loading sound photo " << std::endl;
    }
    if (!soundSliderTextures[5].loadFromFile("assets/images/sound/80.png"))
    {
        std::cout << "error on loading sound photo " << std::endl;
    }
    if (!soundSliderTextures[6].loadFromFile("assets/images/sound/100.png"))
    {
        std::cout << "error on loading sound photo " << std::endl;
    }
    soundSliderSprite.setTexture(soundSliderTextures[current_sound_texture]);
    soundSliderSprite.setOrigin(sf::Vector2f(soundSliderSprite.getLocalBounds().width / 2, soundSliderSprite.getLocalBounds().height / 2));
    soundSliderSprite.setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2));
}

void soundUpdate(sf::RenderWindow &window, Menu &SoundMenu)
{

    while (window.pollEvent(event))
    {
        updateMenu(SoundMenu, event);

        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                if (current_sound_texture == 6)
                {
                    break;
                }

                current_sound_texture++;
                soundSliderSprite.setTexture(soundSliderTextures[current_sound_texture]);
            }
            if (event.key.code == sf::Keyboard::Left)
            {
                if (current_sound_texture == 0)
                {
                    break;
                }

                current_sound_texture--;
                soundSliderSprite.setTexture(soundSliderTextures[current_sound_texture]);
            }
            if (event.key.code == sf::Keyboard::Enter)

            {
                current_screen = 3;
            }
        }
    }
}

void soundDraw(sf::RenderWindow &window, Menu &SoundMenu)
{
    drawMenu(SoundMenu, window, "Sound Menu");
    window.draw(soundSliderSprite);
}
Menu initlizeSoundMenu()
{
    char *items[3] = {"Go Back", "", ""};
    Menu SoundMenu = initlizeMenu(3, items);
    return SoundMenu;
}
