#pragma once
#include <string>
#include <SFML/Graphics/Text.hpp>

#include "TextSettings.h"
#include "../UIObject.h"

class Text : public UIObject
{
public:
    Text();
    ~Text() override = default;
    
    void setupFont(const sf::Font* font) const;
    void setup(const std::string& text = "", unsigned int size = 12,
         const sf::Color& color = sf::Color::White, unsigned int style = sf::Text::Regular,
         const sf::Color& outline = sf::Color::Black, unsigned int outlineThickness = 0) const;

    void setup(const TextSettings& settings) const;
    sf::Drawable* getDrawable() override;
    void setText(const std::string& text) const;
    void setSize(unsigned int size) const;
    void setColor(const sf::Color& color) const;
    void setStyle(unsigned int style) const;
    void setOutline(const sf::Color& outline, unsigned int outlineThickness) const;

    [[nodiscard]] sf::FloatRect getGlobalBounds() const;
protected:
    sf::Transformable* getTransformable() override;

private:
    std::unique_ptr<sf::Text> m_text;
};
