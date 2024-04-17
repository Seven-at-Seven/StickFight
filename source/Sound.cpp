#include "screens/Sound.hpp"
#include "Globals.hpp"
#include <iostream>

sf::Texture textures[7];
sf::Sprite sp;
int current_sound_texture = 3;

bool firstload = true;

void soundUpdate(sf::RenderWindow &window, Menu &SoundMenu)
{

    if (firstload)
    {
        if (!textures[0].loadFromFile("assets/images/sound/0.png"))
        {
            std::cout << "error on loading Sound photo" << std::endl;
        }
        if (!textures[1].loadFromFile("assets/images/sound/20.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[2].loadFromFile("assets/images/sound/40.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[3].loadFromFile("assets/images/sound/50.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[4].loadFromFile("assets/images/sound/60.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[5].loadFromFile("assets/images/sound/80.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[6].loadFromFile("assets/images/sound/100.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }

        sp.setTexture(textures[current_sound_texture]);
        // sp.setTextureRect(sf::IntRect(0, 0, SCREENWIDTH / 2, SCREENHEIGHT / 3));
        sp.setOrigin(sf::Vector2f(sp.getLocalBounds().width / 2, sp.getLocalBounds().height / 2));
        sp.setPosition(sf::Vector2f(SCREENWIDTH / 2, SCREENHEIGHT / 2));
        firstload = false;
    }

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
                sp.setTexture(textures[current_sound_texture]);
            }
            if (event.key.code == sf::Keyboard::Left)
            {
                if (current_sound_texture == 0)
                {
                    break;
                }

                current_sound_texture--;
                sp.setTexture(textures[current_sound_texture]);
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
    window.draw(sp);
}
Menu initlizeSoundMenu()
{
    char *items[3] = {"Go Back", "", ""};
    Menu SoundMenu = initlizeMenu(3, items);
    return SoundMenu;
}
