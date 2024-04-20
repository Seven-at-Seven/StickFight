#include "screens/Colors.hpp"
#include "Globals.hpp"
#include <iostream>
#include <vector>

sf::RectangleShape current_rect;

sf::RectangleShape rectTopLeft;
sf::RectangleShape rectTopRight;
sf::RectangleShape rectBottomLeft;
sf::RectangleShape rectBottomRight;

sf::Vector2f size = sf::Vector2f(400.0f, 400.0f);

float x = size.x / 4;
float y = size.y / 4;

float originX = x / 2;
float originY = y / 2;
float centerX = SCREENWIDTH / 2;
float centerY = SCREENHEIGHT / 2;

float delta = 10.f;

sf::Color brown(150, 75, 0);

std::vector<sf::Color> colors = {
    brown,
    sf::Color::Green,
    sf::Color::Cyan};

bool firstloadColors = true;

void setupRect(sf::RectangleShape rect, sf::Color color)
{
    rect.setSize(sf::Vector2f(x, y));
    rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
    rect.setFillColor(color);
}

void colorsDraw(sf::RenderWindow &window, Menu &Menu)
{
    // drawMenu(Menu, window, "Sound Menu");
    window.draw(rectTopLeft);
    window.draw(rectTopRight);
    window.draw(rectBottomLeft);
    window.draw(rectBottomRight);
    window.draw(current_rect);
}

int current_square = 1;
int current_color = 0;

void colorsUpdate(sf::RenderWindow &window, Menu &Menu)
{

    if (firstloadColors)
    {
        rectTopLeft.setSize(sf::Vector2f(x, y));
        rectTopLeft.setOrigin(sf::Vector2f(rectTopLeft.getSize().x / 2, rectTopLeft.getSize().y / 2));
        rectTopLeft.setFillColor(sf::Color::Red);
        rectTopLeft.setPosition(centerX - originX - delta, centerY - originY - delta);

        // rectTopRight
        rectTopRight.setSize(sf::Vector2f(x, y));
        rectTopRight.setOrigin(sf::Vector2f(originX, originY));
        rectTopRight.setFillColor(sf::Color::Yellow);
        rectTopRight.setPosition(centerX + originX + delta, centerY - originY - delta);

        // rectBottomLeft
        rectBottomLeft.setSize(sf::Vector2f(x, y));
        rectBottomLeft.setOrigin(sf::Vector2f(originX, originY));
        rectBottomLeft.setFillColor(sf::Color::Magenta);
        rectBottomLeft.setPosition(centerX - originX - delta, centerY + originY + delta);

        // rectBottomLeft
        rectBottomRight.setSize(sf::Vector2f(x, y));
        rectBottomRight.setOrigin(sf::Vector2f(originX, originY));
        rectBottomRight.setFillColor(sf::Color::Blue);
        rectBottomRight.setPosition(centerX + originX + delta, centerY + originY + delta);
        current_rect = rectTopLeft;
        current_rect.setOutlineThickness(4.f);
        current_rect.setOutlineColor(sf::Color::White);
        window.draw(rectTopLeft);
        window.draw(rectTopRight);
        window.draw(rectBottomLeft);
        window.draw(rectBottomRight);
        window.draw(current_rect);
        firstloadColors = false;
    }

    while (window.pollEvent(event))
    {
        updateMenu(Menu, event);

        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                ++current_square;
                switch (current_square)
                {
                case 1:
                    current_rect.setPosition(rectTopLeft.getPosition());
                    current_rect.setFillColor(rectTopLeft.getFillColor());
                    break;
                case 2:
                    current_rect.setPosition(rectTopRight.getPosition());
                    current_rect.setFillColor(rectTopRight.getFillColor());
                    break;
                case 3:
                    current_rect.setPosition(rectBottomLeft.getPosition());
                    current_rect.setFillColor(rectBottomLeft.getFillColor());
                    break;
                case 4:
                    current_rect.setPosition(rectBottomRight.getPosition());
                    current_rect.setFillColor(rectBottomRight.getFillColor());
                    break;
                default:
                    current_square = 1;
                    current_rect.setPosition(rectTopLeft.getPosition());
                    current_rect.setFillColor(rectTopLeft.getFillColor());
                    break;
                }
            }
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            --current_square;
            switch (current_square)
            {
            case 1:
                current_rect.setPosition(rectTopLeft.getPosition());
                current_rect.setFillColor(rectTopLeft.getFillColor());
                break;
            case 2:
                current_rect.setPosition(rectTopRight.getPosition());
                current_rect.setFillColor(rectTopRight.getFillColor());
                break;
            case 3:
                current_rect.setPosition(rectBottomLeft.getPosition());
                current_rect.setFillColor(rectBottomLeft.getFillColor());
                break;
            case 4:
                current_rect.setPosition(rectBottomRight.getPosition());
                current_rect.setFillColor(rectBottomRight.getFillColor());
                break;
            default:
                current_square = 4;
                current_rect.setPosition(rectBottomRight.getPosition());
                current_rect.setFillColor(rectBottomRight.getFillColor());
                break;
            }
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            if (current_color > colors.size())
            {
                current_color = 0;
            }
            current_rect.setFillColor(colors[current_color]);
            switch (current_square)
            {
            case 1:
                colors.push_back(rectTopLeft.getFillColor());
                rectTopLeft.setFillColor(colors[current_color]);
                break;
            case 2:
                colors.push_back(rectTopRight.getFillColor());
                rectTopRight.setFillColor(colors[current_color]);
                break;
            case 3:
                colors.push_back(rectBottomLeft.getFillColor());
                rectBottomLeft.setFillColor(colors[current_color]);

                break;
            case 4:
                colors.push_back(rectBottomRight.getFillColor());
                rectBottomRight.setFillColor(colors[current_color]);
                break;
            }
            colors.erase(colors.begin() + current_color);
            ++current_color;
        }
    }
}

Menu initlizeColorsMenu()
{
    char *items[3] = {"Go Back", "", ""};
    Menu Menu = initlizeMenu(3, items);
    return Menu;
}
