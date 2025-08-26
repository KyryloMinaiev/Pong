#include "Image.h"

#include <SFML/Graphics/Texture.hpp>

Image::Image()
{
    sf::Texture texture;
    m_sprite = std::make_unique<sf::Sprite>(texture);
}

sf::Drawable* Image::getDrawable()
{
    return m_sprite.get();
}

Image::~Image() = default;

void Image::setTexture(const sf::Texture* texture) const
{
    m_sprite->setTexture(*texture, true); 
}

void Image::setColor(const sf::Color& color) const
{
    m_sprite->setColor(color);
}

sf::Transformable* Image::getTransformable()
{
    return m_sprite.get();
}
