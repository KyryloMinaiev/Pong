
module ImageFactory;

ImageFactory::~ImageFactory() = default;

void ImageFactory::inject(GameInterface* gameInterface, ITextureContainer* textureContainer)
{
    m_gameInterface = gameInterface;
    m_textureContainer = textureContainer; 
}

Image* ImageFactory::createImage(sf::Texture* texture, const std::string& name)
{
    Image* image = m_gameInterface->createUIObjectOfType<Image>(name);
    image->setTexture(texture);
    return image;
}

Image* ImageFactory::createImage(const std::filesystem::path& filename, const std::string& name)
{
    sf::Texture* texture = m_textureContainer->getTexture(filename);
    return createImage(texture, name);
}
