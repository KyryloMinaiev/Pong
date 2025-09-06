#include "SFML/SFMLImport.h"

module Text;

import <memory>;

void Text::setup(const std::string& text, unsigned int size, const sf::Color& color, unsigned int style,
                 const sf::Color& outline, unsigned int outlineThickness) const
{
    setText(text);
    setSize(size);
    setColor(color);
    setStyle(style);
    setOutline(outline, outlineThickness);
}

void Text::setup(const TextSettings& settings) const
{
    setup(settings.text, settings.size, settings.color,
          settings.style, settings.outline, settings.outlineThickness);
}

Text::Text()
{
    sf::Font font;
    m_text = std::make_unique<sf::Text>(font); 
}

void Text::setupFont(const sf::Font* font) const
{
    m_text->setFont(*font);
}

sf::Drawable* Text::getDrawable()
{
    return m_text.get();
}

void Text::setText(const std::string& text) const
{
    m_text->setString(text);
}

void Text::setSize(unsigned int size) const
{
    m_text->setCharacterSize(size);  
}

void Text::setColor(const sf::Color& color) const
{
    m_text->setFillColor(color);
}

void Text::setStyle(unsigned int style) const
{
    m_text->setStyle(style);
}

void Text::setOutline(const sf::Color& outline, unsigned int outlineThickness) const
{
    m_text->setOutlineColor(outline);
    m_text->setOutlineThickness(outlineThickness);
}

sf::FloatRect Text::getGlobalBounds() const
{
    return m_text->getGlobalBounds();
}

sf::Transformable* Text::getTransformable()
{
    return m_text.get();
}
