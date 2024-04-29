#include "components/HealthBar.hpp"
#include "Globals.hpp"
#include "Configurations.hpp"

HealthBar healthBarArray[MAX_PLAYERS_NUMBER];

sf::Font deathMessageFont;
sf::Text deathMessage;

void loadHealthBarAssets()
{
    deathMessageFont.loadFromFile("assets/Surum.ttf");
    for (int i = 0; i < MAX_PLAYERS_NUMBER; i++)
    {
        healthBarArray[i].currentHP = 100;
        healthBarArray[i].healthRectangle.setFillColor(palyersColors[i]);
        healthBarArray[i].healthRectangle.setSize(sf::Vector2f(30 * healthBarArray[i].currentHP, 20));
        healthBarArray[i].healthRectangle.setPosition(sf::Vector2f(SCREENWIDTH - 320, 30 * (i + 1)));
    }
}

void drawHealthBar(sf::RenderWindow &window)
{
    for (int i = 0; i < number_of_players; i++)
    {
        healthBarArray[i].healthRectangle.setSize(sf::Vector2f(3 * healthBarArray[i].currentHP, 20));
        if (healthBarArray[i].currentHP <= 0)
        {
            healthBarArray[i].currentHP = 0;
            deathMessage.setFont(deathMessageFont);
            deathMessage.setString("DEAD");
            deathMessage.setFillColor(charactersArray[i].color);
            deathMessage.setPosition(healthBarArray[i].healthRectangle.getPosition());
            window.draw(deathMessage);
            charactersArray[i].isDead = true;
            charactersArray[i].isHavingGun = false;
        }
        window.draw(healthBarArray[i].healthRectangle);
    }
}
