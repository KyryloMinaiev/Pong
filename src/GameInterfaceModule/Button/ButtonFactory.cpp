#include "ButtonFactory.h"

#include "../GameInterface.h"
#include "../../ITextureContainer.h"
#include "../Text/ITextFactory.h"
#include "../Text/Text.h"

ButtonFactory::~ButtonFactory() = default;

void ButtonFactory::inject(GameInterface* gameInterface, ITextureContainer* textureContainer, ITextFactory* textFactory)
{
    m_gameInterface = gameInterface;
    m_textureContainer = textureContainer;
    m_textFactory = textFactory;
}

Button* ButtonFactory::createButton(sf::Texture* texture, const std::string& text, const std::string& name)
{
    Button* button = m_gameInterface->createUIObjectOfType<Button>(name);
    button->setTexture(texture);
    if (!text.empty())
    {
        Text* textObject = m_textFactory->createText();
        textObject->setText(text);
        textObject->setParent(button);
    }
    
    return button;  
}

Button* ButtonFactory::createButton(const std::filesystem::path& filename, const std::string& text, const std::string& name)
{
    sf::Texture* texture = m_textureContainer->getTexture(filename);
    return createButton(texture, text, name); 
}
