#include "SFML/SFMLImport.h"

export module IFontsProvider;

export class IFontsProvider
{
public:
    virtual ~IFontsProvider() = default;
    virtual sf::Font* getDefaultFont() = 0;
};
