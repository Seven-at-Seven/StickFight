#include "../headers/screens/PlaySettings.hpp"
#include "../headers/Globals.hpp"

void playSettingsUpdate(sf::RenderWindow &window)
{

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void playSettingsDraw(sf::RenderWindow &window)
{
}