#pragma once
#include <memory>
#include <SFML/Graphics/Transformable.hpp>

#include "Object.h"

class TransformableObject : public Object
{
public:
    TransformableObject();
    TransformableObject(sf::Transformable* transformable);
    ~TransformableObject() override;

    void setPosition(sf::Vector2f position) const;
    void setRotation(sf::Angle angle) const;
    void setScale(sf::Vector2f scale) const;
    void setOrigin(sf::Vector2f origin) const;

    sf::Vector2f getPosition() const;
    sf::Angle getRotation() const;
    sf::Vector2f getScale() const;
    sf::Vector2f getOrigin() const;

    void move(sf::Vector2f offset) const;
    void rotate(sf::Angle angle) const;
    void scale(sf::Vector2f factor) const;
private:
    std::unique_ptr<sf::Transformable> m_transformable;
    sf::Transformable* m_transformablePtr;
};
