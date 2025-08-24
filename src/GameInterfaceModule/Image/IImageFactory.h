#pragma once
#include <filesystem>

#include "Image.h"

class IImageFactory
{
public:
    virtual ~IImageFactory() = default;
    virtual Image* createImage(sf::Texture* texture) = 0;
    virtual Image* createImage(const std::filesystem::path& filename) = 0;
};
