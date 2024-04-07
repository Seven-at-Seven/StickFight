#include "../headers/screens/Options.hpp"
#include "../headers/Globals.hpp"
#include "../headers/components/NavButton.hpp"

NavButton nav = initNavButton(sf::Vector2f(20.f, 20.f), sf::Vector2f(150.f, 75.f), "Main Menu");

bool isMouseOverNavButton(sf::RenderWindow &window, NavButton &navButton)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return navButton.buttonRec.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
void onNavButtonClick()
{
    std::cout << "onClick" << std::endl;
    current_screen = 0;
}

void optionsUpdate(sf::RenderWindow &window)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            std::cout << "onClick" << std::endl;
            if (isMouseOverNavButton(window, nav))
            {
                onNavButtonClick();
            }
        }
    }
}

void optionsDraw(sf::RenderWindow &window)
{
    drawNavButton(window, nav);
}