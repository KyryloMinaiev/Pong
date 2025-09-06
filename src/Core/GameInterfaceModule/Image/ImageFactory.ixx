#include "SFML/SFMLImport.h"

export module ImageFactory;

import GameInterface;
import IImageFactory;
import ITextureContainer;
import Image;
import <filesystem>;

export class ImageFactory : public IImageFactory
{
public:
    ~ImageFactory() override;
    void inject(GameInterface* gameInterface, ITextureContainer* textureContainer);
    Image* createImage(sf::Texture* texture, const std::string& name = "Image") override;
    Image* createImage(const std::filesystem::path& filename, const std::string& name = "Image") override;

private:
    GameInterface* m_gameInterface;
    ITextureContainer* m_textureContainer;
};
