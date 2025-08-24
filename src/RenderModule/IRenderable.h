#pragma once
#include <SFML/Graphics/Drawable.hpp>

class IRenderable
{
public:
    ~IRenderable() = default;
    virtual sf::Drawable* getDrawable() = 0;
};
