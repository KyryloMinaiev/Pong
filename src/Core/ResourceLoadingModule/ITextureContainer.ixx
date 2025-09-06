#include "SFML/SFMLImport.h"

export module ITextureContainer;

export class ITextureContainer
{
public:
    virtual ~ITextureContainer() = default;
    virtual sf::Texture* getTexture(const std::filesystem::path& filename) = 0;
};
