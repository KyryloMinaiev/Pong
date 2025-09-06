#include "SFML/SFMLImport.h"

export module Image;

import <memory>;
import UIObject;

export class Image : public UIObject
{
public:
    Image();
    
    sf::Drawable* getDrawable() override;
    ~Image() override;

    void setTexture(const sf::Texture* texture) const;
    void setColor(const sf::Color& color) const;
protected:
    sf::Transformable* getTransformable() override;

private:
    std::unique_ptr<sf::Sprite> m_sprite;
};
