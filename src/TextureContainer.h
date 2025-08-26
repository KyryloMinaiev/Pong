#pragma once
#include <unordered_map>

#include "ITextureContainer.h"

class TextureContainer : public ITextureContainer
{
public:
    ~TextureContainer() override;
    sf::Texture* getTexture(const std::filesystem::path& filename) override;
private:
    std::unordered_map<std::filesystem::path, std::unique_ptr<sf::Texture>> m_textures;
};
