#include "TransformableObject.h"

TransformableObject::TransformableObject() : m_transformable(std::make_unique<sf::Transformable>()), m_transformablePtr(m_transformable.get())
{
}

TransformableObject::TransformableObject(sf::Transformable* transformable) : m_transformablePtr(transformable)
{
}

TransformableObject::~TransformableObject() = default;

void TransformableObject::setPosition(sf::Vector2f position) const
{
    m_transformablePtr->setPosition(position);  
}

void TransformableObject::setRotation(sf::Angle angle) const
{
    m_transformablePtr->setRotation(angle); 
}

void TransformableObject::setScale(sf::Vector2f scale) const
{
    m_transformablePtr->setScale(scale);
}

void TransformableObject::setOrigin(sf::Vector2f origin) const
{
    m_transformablePtr->setOrigin(origin);
}

sf::Vector2f TransformableObject::getPosition() const
{
    return m_transformablePtr->getPosition(); 
}

sf::Angle TransformableObject::getRotation() const
{
    return m_transformablePtr->getRotation();
}

sf::Vector2f TransformableObject::getScale() const
{
    return m_transformablePtr->getScale();
}

sf::Vector2f TransformableObject::getOrigin() const
{
    return m_transformablePtr->getOrigin();
}

void TransformableObject::move(sf::Vector2f offset) const
{
    m_transformablePtr->move(offset);
}

void TransformableObject::rotate(sf::Angle angle) const
{
    m_transformablePtr->rotate(angle);
}

void TransformableObject::scale(sf::Vector2f factor) const
{
    m_transformablePtr->scale(factor);
}
