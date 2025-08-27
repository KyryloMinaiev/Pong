#include "WindowSequenceService.h"

WindowSequenceService::~WindowSequenceService() = default;

void WindowSequenceService::inject(sf::RenderWindow* window, WindowEventHandler* windowEventHandler)
{
    m_window = window;
    m_windowEventHandler = windowEventHandler;
}

void WindowSequenceService::initialize()
{
    m_windowEventHandler->addEventListener(CreateAction(this, &WindowSequenceService::onWindowClosedEvent));
}

void WindowSequenceService::onWindowClosedEvent(const sf::Event::Closed* closedEvent)
{
    m_window->close();  
}
