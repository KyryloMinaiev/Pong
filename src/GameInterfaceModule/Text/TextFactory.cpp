#include "TextFactory.h"

#include "../GameInterface.h"
#include "../IFontsProvider.h"

TextFactory::~TextFactory() = default;

void TextFactory::inject(GameInterface* gameInterface, IFontsProvider* fontsProvider)
{
    m_gameInterface = gameInterface;
    m_fontsProvider = fontsProvider;  
}

Text* TextFactory::createText(const std::string& name, const TextSettings& settings)
{
    Text* text = m_gameInterface->createUIObjectOfType<Text>(name);
    text->setupFont(m_fontsProvider->getDefaultFont());
    text->setup(settings);

    return text;   
}
