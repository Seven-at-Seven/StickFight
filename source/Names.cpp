#include "Names.hpp"
#include "components/Character.hpp"

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
    bg_sprite.setPosition(sf::Vector2f(700, 200));
    sf::Font font;
    sf::Text main_text;
    if (!font.loadFromFile("assets/VCR_OSD_MONO.ttf")) // change font from here
    {
        std::cout << "Error loading font: assets/VCR_OSD_MONO.ttf" << std::endl;
    }
    main_text.setFont(font);
    main_text.setString("Enter Players' names: ");
    main_text.setCharacterSize(65);
    main_text.setPosition(10, 10);
    main_text.setFillColor(sf::Color(255, 204, 0));
    for (int i = 0, multiple = 100; i < number_of_players; i++, multiple += 55)
    {
        names_text[i].setFont(font);
        names_text[i].setCharacterSize(55);
        names_text[i].setPosition(10, multiple);
        names_text[i].setFillColor(charactersArray[i].color);
        names_text[i].setString(charactersArray[i].name);
    }

    window.draw(bg_sprite);
    window.draw(main_text);
    for (int i = 0; i < number_of_players; i++)
    {
        window.draw(names_text[i]);
    }
}
int state = 0;
void NamesUpdate(sf::RenderWindow &window)
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
                charactersArray[0].name += static_cast<char>(event.text.unicode);
                break;
            case 1:
                charactersArray[1].name += static_cast<char>(event.text.unicode);
                break;
            case 2:
                charactersArray[2].name += static_cast<char>(event.text.unicode);
                break;
            case 3:
                charactersArray[3].name += static_cast<char>(event.text.unicode);
                break;
            default:
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && charactersArray[state].name.size() > 0)
        {
            charactersArray[state].name.pop_back();
        }
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                charactersArray[state].name.pop_back();
                if(!charactersArray[state].name.empty()) 
                state++;
                if (state >= number_of_players)
                {
                    current_screen = 2;
                    state = 0;
                    return;
                }
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                charactersArray[state].name.pop_back();
                current_screen = 1;
                return;
            }
        }
    }
}