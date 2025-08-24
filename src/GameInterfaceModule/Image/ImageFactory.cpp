#include "ImageFactory.h"

#include "../GameInterface.h"

ImageFactory::~ImageFactory() = default;

void ImageFactory::inject(GameInterface* gameInterface, ITextureContainer* textureContainer)
{
    m_gameInterface = gameInterface;
    m_textureContainer = textureContainer; 
}

Image* ImageFactory::createImage(sf::Texture* texture)
{
    Image* image = m_gameInterface->createUIObjectOfType<Image>();
    image->setTexture(texture);
    return image;
}

Image* ImageFactory::createImage(const std::filesystem::path& filename)
{
    Image* image = m_gameInterface->createUIObjectOfType<Image>();
    sf::Texture* texture = m_textureContainer->getTexture(filename);
    image->setTexture(texture);
    return image;
}
