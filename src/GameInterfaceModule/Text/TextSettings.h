#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>

struct TextSettings
{
    std::string text;
    unsigned int size;
    sf::Color color;
    unsigned int style;
    sf::Color outline;
    unsigned int outlineThickness;

    TextSettings(std::string text = "New Text", unsigned int size = 12,
         const sf::Color& color = sf::Color::White, unsigned int style = sf::Text::Regular,
         const sf::Color& outline = sf::Color::Black, unsigned int outlineThickness = 0);
};
