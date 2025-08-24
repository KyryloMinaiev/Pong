#pragma once
#include "IImageFactory.h"
#include "../../ITextureContainer.h"

class GameInterface;

class ImageFactory : public IImageFactory
{
public:
    ~ImageFactory() override;
    void inject(GameInterface* gameInterface, ITextureContainer* textureContainer);
    Image* createImage(sf::Texture* texture) override;
    Image* createImage(const std::filesystem::path& filename) override;

private:
    GameInterface* m_gameInterface;
    ITextureContainer* m_textureContainer;
};
