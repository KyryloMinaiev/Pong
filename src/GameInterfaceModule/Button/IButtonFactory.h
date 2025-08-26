#pragma once
#include <filesystem>

#include "Button.h"

class IButtonFactory
{
public:
    virtual ~IButtonFactory() = default;
    virtual Button* createButton(sf::Texture* texture, const std::string& text = nullptr, const std::string& name = "Button") = 0;
    virtual Button* createButton(const std::filesystem::path& filename, const std::string& text = nullptr, const std::string& name = "Button") = 0;
};
