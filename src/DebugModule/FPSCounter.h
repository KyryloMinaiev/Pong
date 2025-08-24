#pragma once

#include "../Core/DIContainer/IInitializable.h"
#include "../Core/DIContainer/IUpdatable.h"
#include "../GameInterfaceModule/Text/ITextFactory.h"

class Text;

class FPSCounter : public IUpdatable, public IInitializable
{
public:
    ~FPSCounter() override;

    void inject(ITextFactory* textFactory);
    void initialize() override;
    void update(float deltaTime) override;

private:
    ITextFactory* m_textFactory;
    Text* m_fpsCounterText;
};
