#pragma once
#include <SFML/Graphics/Texture.hpp>

class ITextureContainer
{
public:
    virtual ~ITextureContainer() = default;
    virtual sf::Texture* getTexture(const std::filesystem::path& filename) = 0;
};
