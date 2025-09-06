#include "SFML/SFMLImport.h"

export module TransformableObject;

import Object;
import <memory>;

export class TransformableObject : public Object
{
public:
    ~TransformableObject() override;

    void setPosition(sf::Vector2f position);
    void setRotation(sf::Angle angle);
    void setScale(sf::Vector2f scale);
    void setOrigin(sf::Vector2f origin);

    sf::Vector2f getPosition();
    sf::Angle getRotation();
    sf::Vector2f getScale();
    sf::Vector2f getOrigin();

    void move(sf::Vector2f offset);
    void rotate(sf::Angle angle);
    void scale(sf::Vector2f factor);

protected:
    virtual sf::Transformable* getTransformable();

private:
    std::unique_ptr<sf::Transformable> m_transformable;
};
