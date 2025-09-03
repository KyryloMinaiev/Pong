#pragma once
#include "IButtonFactory.h"

class ITextFactory;
class ITextureContainer;
class GameInterface;
class ObjectsContainer;

class ButtonFactory : public IButtonFactory
{
public:
    ~ButtonFactory() override;
    void inject(GameInterface* gameInterface, ObjectsContainer* objectsContainer, ITextureContainer* textureContainer, ITextFactory* textFactory);
    Button* createButton(sf::Texture* texture, const std::string& text, const std::string& name = "Button") override;
    Button* createButton(const std::filesystem::path& filename, const std::string& text, const std::string& name = "Button") override;
private:
    GameInterface* m_gameInterface;
    ITextureContainer* m_textureContainer;
    ITextFactory* m_textFactory;
    ObjectsContainer* m_objectsContainer;
};
