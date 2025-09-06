#include "SFML/SFMLImport.h"

export module ButtonFactory;

import IButtonFactory;
import Button;
import DIContainer;
import GameInterface;
import ObjectsModule;
import ResourceManagement;
import ITextFactory;
import <filesystem>;

export class ButtonFactory : public IButtonFactory
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
