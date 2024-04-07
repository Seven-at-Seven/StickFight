#include "../headers/components/NavButton.hpp"
#include <iostream>

sf::Text text;

NavButton initNavButton(sf::Vector2f position, sf::Vector2f size, char *text)
{
    NavButton nav = {position, size, text};
    if (!nav.font.loadFromFile("./assets/Suruma.ttf"))
    {
        std::cout << "Error loading font";
    }
    return nav;
}

void drawNavButton(sf::RenderWindow &window, NavButton &navButton)
{

    // handle button text (title)
    text.setFont(navButton.font);
    text.setString(navButton.text);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    // Set text position relative to the rectangle
    // Here we center the text inside the rectangle
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition((navButton.position.x + navButton.size.x) / 2.0f,
                     (navButton.position.y + navButton.size.y) / 2.0f);

    navButton.buttonRec.setSize(navButton.size);
    navButton.buttonRec.setPosition(navButton.position);
    navButton.buttonRec.setPosition(navButton.position);
    navButton.buttonRec.setFillColor(sf::Color::Red);
    window.draw(navButton.buttonRec);
    window.draw(text);
}