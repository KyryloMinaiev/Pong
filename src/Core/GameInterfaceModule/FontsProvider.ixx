#include "SFML/SFMLImport.h"

export module FontsProvider;

import <memory>;
import IFontsProvider;
import IInitializable;

export class FontsProvider : public IFontsProvider, public IInitializable
{
public:
    ~FontsProvider() override;
    void initialize() override;

    sf::Font* getDefaultFont() override;

private:
    std::unique_ptr<sf::Font> m_defaultFont;
};
