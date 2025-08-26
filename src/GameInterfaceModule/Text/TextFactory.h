#pragma once
#include "ITextFactory.h"

class IFontsProvider;
class GameInterface;

class TextFactory : public ITextFactory
{
public:
    ~TextFactory() override;
    void inject(GameInterface* gameInterface, IFontsProvider* fontsProvider);
    
    Text* createText(const std::string& name, const TextSettings& settings) override;

private:
    GameInterface* m_gameInterface;
    IFontsProvider* m_fontsProvider;
};
