#pragma once

#include "../Core/DIContainer/IInitializable.h"
#include "../Core/DIContainer/IUpdatable.h"
#include "../GameInterfaceModule/Text/ITextFactory.h"
#include "../GameInterfaceModule/Image/IImageFactory.h"

class Text;

class FPSCounter : public IUpdatable, public IInitializable
{
public:
    ~FPSCounter() override;

    void inject(ITextFactory* textFactory, IImageFactory* imageFactory);
    void initialize() override;
    void update(float deltaTime) override;

private:
    ITextFactory* m_textFactory;
    IImageFactory* m_imageFactory;
    Text* m_fpsCounterText;
    Image* m_background;
};
