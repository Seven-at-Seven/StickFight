#include "Names.hpp"
#include "components/Character.hpp"

void draw_name_screen(sf::RenderWindow &window)
{
}
void NamesDraw(sf::RenderWindow &window)
{
    sf::Text names_text[4];
    sf::Texture bg;
    if (!bg.loadFromFile("assets/images/mainMenuBackground.png"))
    {
        std::cout << "Error loading font: assets/images/mainMenuBackground.png" << '\n';
    }

    sf::Sprite bg_sprite;

    bg_sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));
    bg_sprite.setTexture(bg);
    bg_sprite.setPosition(sf::Vector2f(700, 100));
    sf::Font font;
    sf::Text t;
    if (!font.loadFromFile("assets/VCR_OSD_MONO.ttf")) // change font from here
    {
        std::cout << "Error loading font: assets/VCR_OSD_MONO.ttf" << std::endl;
    }
    t.setFont(font);
    t.setString("Enter Players' names: ");
    t.setCharacterSize(65);
    t.setPosition(10, 10);
    t.setFillColor(sf::Color(255, 204, 0));
    for (int i = 0, multiple = 70; i < number_of_players; i++, multiple += 55)
    {
        names_text[i].setFont(font);
        names_text[i].setCharacterSize(55);
        names_text[i].setPosition(10, multiple);
        names_text[i].setFillColor(charactersArray[i].color);
        names_text[i].setString(charactersArray[i].name);
    }

    window.draw(bg_sprite);
    window.draw(t);
    for (int i = 0; i < number_of_players; i++)
    {
        window.draw(names_text[i]);
    }
}
int state = 0;
void NamesUpdate(sf::RenderWindow &window, std::string names[])
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::TextEntered)
        {
            switch (state)
            {
            case 0:
                names[0] += static_cast<char>(event.text.unicode);
                break;
            case 1:
                names[1] += static_cast<char>(event.text.unicode);
                break;
            case 2:
                names[2] += static_cast<char>(event.text.unicode);
                break;
            case 3:
                names[3] += static_cast<char>(event.text.unicode);
                break;
            default:
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && names[state].size() > 0)
        {
            names[state].pop_back();
        }
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Return)
            {
                state++;
                if (state >= number_of_players)
                {
                    current_screen = 2;
                    return;
                }
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                current_screen = 1;
                return;
            }
        }
    }
    for (int i = 0; i < number_of_players; i++)
    {
        charactersArray[i].name = names[i];
    }
}