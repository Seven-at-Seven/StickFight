#include "components/Menu.hpp"
#include <iostream>

Menu initlizeMenu(int numebrOfItems, char **items)
{

    Menu menu;
    menu.width = SCREENWIDTH;
    menu.height = SCREENHEIGHT;
    menu.selectedItem = 0;
    menu.numberOfItems = numebrOfItems;

    if (!menu.font.loadFromFile("./assets/Suruma.ttf"))
    {
        std::cout << "Error loading font: assets/Suruma.ttf" << std::endl;
    }
    for (size_t i = 0; i < numebrOfItems; i++)
    {
        menu.text[i].setFont(menu.font);
        menu.text[i].setColor(sf::Color::White);
        menu.text[i].setString(items[i]);
        menu.text[i].setPosition(sf::Vector2f(menu.width / 2 - 30, menu.height / (numebrOfItems + 1) * (i + 1)));
    }

    return menu;
}

void moveSelectionUp(Menu &menu)
{
    if (menu.selectedItem == 0)
        menu.selectedItem = menu.numberOfItems - 1;
    else
    {
        menu.selectedItem--;
    }
};
void moveSelectionDown(Menu &menu)
{

    if (menu.selectedItem == menu.numberOfItems - 1)
        menu.selectedItem = 0;
    else
    {
        menu.selectedItem++;
    }
};
void updateMenu(Menu &menu)
{

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
}
void drawMenu(Menu &menu, sf::RenderWindow &window)
{

    for (int i = 0; i < menu.numberOfItems; i++)
    {
        if (i == menu.selectedItem)
            menu.text[i].setColor(sf::Color::Red);
        else
            menu.text[i].setColor(sf::Color::White);
        window.draw(menu.text[i]);
    }
};