module FPSCounter;

import <string>;

FPSCounter::~FPSCounter() = default;

void FPSCounter::inject(ITextFactory* textFactory, IImageFactory* imageFactory)
{
    m_textFactory = textFactory;
    m_imageFactory = imageFactory; 
}

void FPSCounter::initialize()
{
    m_background = m_imageFactory->createImage("res/textures/pixel.png");
    m_background->setScale({45, 18});
    m_background->setColor({20, 20, 20, 255});
    m_fpsCounterText = m_textFactory->createText("FPSCounter", TextSettings());
}

void FPSCounter::update(float deltaTime)
{
    m_fpsCounterText->setText("FPS: " + std::to_string(static_cast<int>(1.0f / deltaTime)));
}
