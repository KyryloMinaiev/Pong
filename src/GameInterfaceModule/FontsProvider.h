#pragma once
#include "IFontsProvider.h"
#include "../Core/DIContainer/IInitializable.h"

class FontsProvider : public IFontsProvider, public IInitializable
{
public:
    ~FontsProvider() override;
    void initialize() override;

    sf::Font* getDefaultFont() override;

private:
    std::unique_ptr<sf::Font> m_defaultFont;
};
