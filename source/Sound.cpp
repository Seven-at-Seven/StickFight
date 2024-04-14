#include "screens/Sound.hpp"
#include "Globals.hpp"
#include <iostream>

sf::Texture textures[6];
sf::Sprite sp;
int current_sound_texture = 0;

bool firstload = true;

void soundUpdate(sf::RenderWindow &window)
{

    if (firstload)
    {
        if (!textures[0].loadFromFile("sound.JPG"))
        {
            std::cout << "error on loading Sound photo" << std::endl;
        }
        if (!textures[1].loadFromFile("20.JPG"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[2].loadFromFile("40.JPG"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[3].loadFromFile("60.JPG"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[4].loadFromFile("80.JPG"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[5].loadFromFile("100.JPG"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }

        sp.setTexture(textures[0]);
        sp.setTextureRect(sf::IntRect(0, 0, 1000, 400));
        firstload = false;
    }

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                if (current_sound_texture == 5)
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
        }
    }
}

void soundDraw(sf::RenderWindow &window)
{
    window.draw(sp);
}