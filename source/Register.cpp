#include "screens/Register.hpp"
#include "components/Character.hpp"

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
    sf::Color(255, 192, 203) // pink
};

sf::Vector2f size = sf::Vector2f(80.0f, 80.0f);

sf::RectangleShape colorPalettes[MAX_PLAYERS_NUMBER];

sf::Font font;
sf::Text main_text;
sf::Sprite bg_sprite;
sf::Text names_text[4];
sf::Texture bg;

int current_row = 0;
bool changingColor = true;

void loadRegisterAssets()
{
    if (!font.loadFromFile("assets/VCR_OSD_MONO.ttf")) // change font from here
    {
        std::cout << "Error loading font: assets/VCR_OSD_MONO.ttf" << std::endl;
    }
    if (!bg.loadFromFile("assets/images/mainMenuBackground.png"))
    {
        std::cout << "Error loading font: assets/images/mainMenuBackground.png" << '\n';
    }

    // seting default size and position for color palettes
    for (int i = 0, multiple = 100; i < number_of_players; i++, multiple += 120)
    {
        colorPalettes[i].setSize(size);
        colorPalettes[i].setPosition(sf::Vector2f(10, multiple));
    }
}

void registerDraw(sf::RenderWindow &window)
{

    bg_sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));
    bg_sprite.setTexture(bg);
    bg_sprite.setPosition(sf::Vector2f(700, 200));
    main_text.setFont(font);
    main_text.setString("Enter Players' names: ");
    main_text.setCharacterSize(65);
    main_text.setPosition(10, 10);
    main_text.setFillColor(sf::Color(255, 204, 0));
    window.draw(bg_sprite);
    window.draw(main_text);

    drawColors(window);
    drawNames(window);
}
void registerUpdate(sf::RenderWindow &window)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (changingColor)
            updateColors();
        else
            updateNames();
    }
}

void drawColors(sf::RenderWindow &window)
{

    for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
    {
        if (i == current_row)
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

void updateColors()
{

    if (event.type == sf::Event::KeyReleased)
    {

        if (event.key.code == sf::Keyboard::Space)
        {
            changingColor = false;
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            swapColor = palyersColors[current_row];
            palyersColors[current_row] = availableColors[avaliable_index];
            availableColors[avaliable_index] = swapColor;
            avaliable_index++;
            if (avaliable_index > 2)
                avaliable_index = 0;
            loadCharacterAssets();
            loadHealthBarAssets();
            loadBulletsAssets();
        }
    }
}
void drawNames(sf::RenderWindow &window)
{

    for (int i = 0, multiple = 100; i < number_of_players; i++, multiple += 120)
    {
        names_text[i].setFont(font);
        names_text[i].setCharacterSize(55);
        names_text[i].setPosition(100, multiple);
        names_text[i].setFillColor(charactersArray[i].color);
        names_text[i].setString(charactersArray[i].name);
        window.draw(names_text[i]);
    }
}
void updateNames()
{
    if (event.type == sf::Event::TextEntered)
    {
        charactersArray[current_row].name += static_cast<char>(event.text.unicode);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && charactersArray[current_row].name.size() > 0)
    {
        charactersArray[current_row].name.pop_back();
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            charactersArray[current_row].name.pop_back();
            if (!charactersArray[current_row].name.empty())
            {

                changingColor = true;
                current_row++;
            }
            if (current_row >= number_of_players)
            {
                current_screen = 2;
                current_row = 0;
                return;
            }
        }
        if (event.key.code == sf::Keyboard::Escape)
        {
            charactersArray[current_row].name.pop_back();
            current_screen = 1;
            return;
        }
    }
}