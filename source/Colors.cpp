#include "screens/Colors.hpp"
#include "Configurations.hpp"
#include "components/Character.hpp"
#include "Globals.hpp"
#include "components/HealthBar.hpp"

int current_square = 0;
int avaliable_index = 0;

sf::Color swapColor;
sf::Color palyersColors[MAX_PLAYERS_NUMBER] = {
    sf::Color::Red,
    sf::Color::Yellow,
    sf::Color::Magenta,
    sf::Color::Blue};
sf::Color availableColors[7] = {
    sf::Color::Green,
    sf::Color::Cyan,
    sf::Color(255, 192, 203), // pink
};

sf::Vector2f size = sf::Vector2f(100.0f, 100.0f);

sf::RectangleShape colorPalettes[MAX_PLAYERS_NUMBER];

float plattes_x = SCREENWIDTH / 2 - 150;
float plattes_y = SCREENHEIGHT / 2;

void colorsDraw(sf::RenderWindow &window, Menu &colorsMenu)
{
    drawMenu(colorsMenu, window, "Colors");
    for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
    {
        if (i == current_square)
        {

            colorPalettes[i].setOutlineThickness(4.f);
            colorPalettes[i].setOutlineColor(sf::Color::White);
        }
        else
            colorPalettes[i].setOutlineThickness(0.f);
        colorPalettes[i].setFillColor(palyersColors[i]);
        window.draw(colorPalettes[i]);
    }
}

void loadColorsAssets()
{

    for (int i = 0; i < 4; i++)
    {
        colorPalettes[i].setSize(size);
        colorPalettes[i].setFillColor(palyersColors[i]);
        if (i < 2)
        {
            colorPalettes[i].setPosition(sf::Vector2f(plattes_x + (size.x + 20) * i, plattes_y));
        }
        else
        {
            // i - (4/2) + 1 gives 1 when i = 3 and gives 2 when i = 3
            colorPalettes[i].setPosition(sf::Vector2f(plattes_x + (size.x + 20) * (i - (4 / 2)), plattes_y + size.y + 30));
        }
    }
}

void colorsUpdate(sf::RenderWindow &window, Menu &colorsMenu)
{

    while (window.pollEvent(event))
    {
        updateMenu(colorsMenu, event);

        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right && colorsMenu.selectedItem != 0)
            {
                ++current_square;
                if (current_square > 3)
                    current_square = 0;
            }
            else if (event.key.code == sf::Keyboard::Left && colorsMenu.selectedItem != 0)
            {
                --current_square;
                if (current_square < 0)
                    current_square = 3;
            }
            else if (event.key.code == sf::Keyboard::Enter && colorsMenu.selectedItem != 0)
            {
                swapColor = palyersColors[current_square];
                palyersColors[current_square] = availableColors[avaliable_index];
                availableColors[avaliable_index] = swapColor;
                avaliable_index++;
                if (avaliable_index > 2)
                    avaliable_index = 0;
                loadCharacterAssets();
                loadHealthBarAssets();
            }
            else if (event.key.code == sf::Keyboard::Enter && colorsMenu.selectedItem == 0)
            {
                last_screen = current_screen;
                current_screen = 3;
            }
        }
    }
}

Menu initlizeColorsMenu()
{
    char *items[3] = {"Go Back", "", ""};
    Menu Menu = initlizeMenu(3, items);
    return Menu;
}
