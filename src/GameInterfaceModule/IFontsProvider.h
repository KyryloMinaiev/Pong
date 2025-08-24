#pragma once
#include <SFML/Graphics/Font.hpp>

class IFontsProvider
{
public:
    virtual ~IFontsProvider() = default;
    virtual sf::Font* getDefaultFont() = 0;
};
