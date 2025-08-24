#include "FPSCounter.h"

FPSCounter::~FPSCounter() = default;

void FPSCounter::inject(ITextFactory* textFactory)
{
    m_textFactory = textFactory; 
}

void FPSCounter::initialize()
{
    m_fpsCounterText = m_textFactory->createText("FPSCounter", TextSettings());
}

void FPSCounter::update(float deltaTime)
{
    m_fpsCounterText->setText("FPS: " + std::to_string(1.0f / deltaTime));
}
