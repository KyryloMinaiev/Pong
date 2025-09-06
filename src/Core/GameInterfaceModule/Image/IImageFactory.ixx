#include "SFML/SFMLImport.h"

export module IImageFactory;

import <filesystem>;
import Image;

export class IImageFactory
{
public:
    virtual ~IImageFactory() = default;
    virtual Image* createImage(sf::Texture* texture, const std::string& name = "Image") = 0;
    virtual Image* createImage(const std::filesystem::path& filename, const std::string& name = "Image") = 0;
};
