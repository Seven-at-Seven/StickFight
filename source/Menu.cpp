#include "components/Menu.hpp"
#include "Configurations.hpp"
#include "Globals.hpp"
#include <iostream>

sf::Text menuTitle;
sf::Texture mainMenuBackgroundTexture;
sf::Sprite mainMenuBackgroundSprite;

void loadMenuAssets()
{
    mainMenuBackgroundTexture.loadFromFile("assets/images/mainMenuBackground1.png");

    // mainMenuBackgroundSprite.setTextureRect(sf::IntRect(0, 0, 500, 480));
    mainMenuBackgroundSprite.setTexture(mainMenuBackgroundTexture);
    // mainMenuBackgroundSprite.setPosition(sf::Vector2f(700, 100));
}
Menu initlizeMenu(int numebrOfItems, std::string items[])
{

    Menu menu;
    menu.width = SCREENWIDTH;
    menu.height = SCREENHEIGHT;
    menu.selectedItem = 0;
    menu.numberOfItems = numebrOfItems;

    if (!menu.font.loadFromFile("./assets/VCR_OSD_MONO.ttf")) // change font from here
    {
        std::cout << "Error loading font: assets/VCR_OSD_MONO.ttf" << std::endl;
    }
    for (size_t i = 0; i < numebrOfItems; i++)
    {
        menu.text[i].setFont(menu.font);
        menu.text[i].setFillColor(sf::Color::White);
        menu.text[i].setString(items[i]);
        menu.text[i].setCharacterSize(42);
        menu.text[i].setOrigin(sf::Vector2f(menu.text[i].getGlobalBounds().width / 2, menu.text[i].getGlobalBounds().height / 2));
        menu.text[i].setPosition(sf::Vector2f(SCREENWIDTH / 2, menu.height / (numebrOfItems + 2) * (i + 1) + 100));
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

void updateMenu(Menu &menu, sf::Event &event)
{

    if (event.key.code == sf::Keyboard::Up)
    {
        moveSelectionUp(menu);
    }
    if (event.key.code == sf::Keyboard::Down)
    {
        moveSelectionDown(menu);
    }
    if (event.key.code == sf::Keyboard::Escape)
    {

        current_screen = last_screen;
        last_screen = 0;
    }
}

void drawMenu(Menu &menu, sf::RenderWindow &window, std::string title)
{
    // Menu Background
    window.draw(mainMenuBackgroundSprite);

    for (int i = 0; i < menu.numberOfItems; i++)
    {
        if (i == menu.selectedItem)
            menu.text[i].setFillColor(sf::Color(255, 204, 0));
        else
            menu.text[i].setFillColor(sf::Color::White);
        window.draw(menu.text[i]);
    }

    // Menu title
    menuTitle.setString(title);
    menuTitle.setFont(menu.font);
    menuTitle.setPosition(sf::Vector2f(SCREENWIDTH - 10 - menuTitle.getGlobalBounds().width, 20));
    menuTitle.setFillColor(sf::Color::Black);
    window.draw(menuTitle);
};