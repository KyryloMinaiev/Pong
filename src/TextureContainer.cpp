#include "TextureContainer.h"

TextureContainer::~TextureContainer() = default;

sf::Texture* TextureContainer::getTexture(const std::filesystem::path& filename)
{
    if (m_textures.contains(filename))
    {
        return m_textures[filename].get();
    }

    auto texture = std::make_unique<sf::Texture>(filename);
    sf::Texture* texture_ptr = texture.get();
    m_textures[filename] = std::move(texture);
    return texture_ptr; 
}
