#include "SFML/SFMLImport.h"

module TransformableObject;

TransformableObject::~TransformableObject() = default;

void TransformableObject::setPosition(sf::Vector2f position)
{
    getTransformable()->setPosition(position);  
}

void TransformableObject::setRotation(sf::Angle angle)
{
    getTransformable()->setRotation(angle); 
}

void TransformableObject::setScale(sf::Vector2f scale)
{
    getTransformable()->setScale(scale);
}

void TransformableObject::setOrigin(sf::Vector2f origin)
{
    getTransformable()->setOrigin(origin);
}

sf::Vector2f TransformableObject::getPosition()
{
    return getTransformable()->getPosition(); 
}

sf::Angle TransformableObject::getRotation()
{
    return getTransformable()->getRotation();
}

sf::Vector2f TransformableObject::getScale()
{
    return getTransformable()->getScale();
}

sf::Vector2f TransformableObject::getOrigin()
{
    return getTransformable()->getOrigin();
}

void TransformableObject::move(sf::Vector2f offset)
{
    getTransformable()->move(offset);
}

void TransformableObject::rotate(sf::Angle angle)
{
    getTransformable()->rotate(angle);
}

void TransformableObject::scale(sf::Vector2f factor)
{
    getTransformable()->scale(factor);
}

sf::Transformable* TransformableObject::getTransformable()
{
    if (!m_transformable)
    {
        m_transformable = std::make_unique<sf::Transformable>();
    }

    return m_transformable.get();
}
