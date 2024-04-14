#include "screens/Sound.hpp"
#include "Globals.hpp"
#include <iostream>

sf::Texture textures[7];
sf::Sprite sp;
int current_sound_texture = 3;

bool firstload = true;

void soundUpdate(sf::RenderWindow &window)
{

    if (firstload)
    {
        if (!textures[0].loadFromFile("0.png"))
        {
            std::cout << "error on loading Sound photo" << std::endl;
        }
        if (!textures[1].loadFromFile("20.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[2].loadFromFile("40.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[3].loadFromFile("50.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[4].loadFromFile("60.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[5].loadFromFile("80.png"))
        {
            std::cout << "error on loading sound photo " << std::endl;
        }
        if (!textures[6].loadFromFile("100.png"))
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
        }
    }
}

void soundDraw(sf::RenderWindow &window)
{
    window.draw(sp);
}