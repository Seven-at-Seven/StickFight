#include "../headers/screens/MainMenu.hpp"
#include "../headers/Globals.hpp"
#include <unistd.h>
#include <iostream>

void mainUpdate(Menu &menu, int &current_screen, sf::RenderWindow &window)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveSelectionUp(menu);
        usleep(200000);
    }
    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveSelectionDown(menu);
        usleep(200000);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        switch (menu.selectedItem)
        {
        case 0:
            current_screen = 1;
            break;
        case 1:
            current_screen = 3;
            break;
        case 2:
            window.close();
        default:
            break;
        }
    }
}

Menu initlizeMainMenu()
{
    Menu menu;
    menu.width = SCREENWIDTH;
    menu.height = SCREENHEIGHT;
    menu.selectedItem = 0;

    if (!menu.font.loadFromFile("./assets/Suruma.ttf"))
    {
        // handle error
    }
    menu.text[0].setFont(menu.font);
    menu.text[0].setColor(sf::Color::White);
    menu.text[0].setString("Play");
    menu.text[0].setPosition(sf::Vector2f(menu.width / 2 - 30, menu.height / MAX_NUMBER_OF_ITEMS + 1));

    menu.text[1].setFont(menu.font);
    menu.text[1].setColor(sf::Color::White);
    menu.text[1].setString("Options");
    menu.text[1].setPosition(sf::Vector2f(menu.width / 2 - 30, menu.height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu.text[2].setFont(menu.font);
    menu.text[2].setColor(sf::Color::White);
    menu.text[2].setString("Exit");
    menu.text[2].setPosition(sf::Vector2f(menu.width / 2 - 30, menu.height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    return menu;
}

void moveSelectionUp(Menu &menu)
{
    if (menu.selectedItem == 0)
        menu.selectedItem = 2;
    else
    {
        menu.selectedItem--;
    }
};
void moveSelectionDown(Menu &menu)
{

    if (menu.selectedItem == 2)
        menu.selectedItem = 0;
    else
    {
        menu.selectedItem++;
    }
};
void mainDraw(Menu &menu, sf::RenderWindow &window)
{

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        if (i == menu.selectedItem)
            menu.text[i].setColor(sf::Color::Red);
        else
            menu.text[i].setColor(sf::Color::White);
        window.draw(menu.text[i]);
    }
};
