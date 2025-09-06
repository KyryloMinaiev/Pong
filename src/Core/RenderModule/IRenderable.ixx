#include "SFML/SFMLImport.h"

export module IRenderable;

export class IRenderable
{
public:
    ~IRenderable() = default;
    virtual sf::Drawable* getDrawable() = 0;
};
