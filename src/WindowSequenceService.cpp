#include "WindowSequenceService.h"

WindowSequenceService::WindowSequenceService()
{
    m_windowClosedAction = CreateAction(this, &WindowSequenceService::onWindowClosedEvent);
}

WindowSequenceService::~WindowSequenceService()
{
    m_windowEventHandler->removeEventListener(m_windowClosedAction); 
}

void WindowSequenceService::inject(sf::RenderWindow* window, WindowEventHandler* windowEventHandler)
{
    m_window = window;
    m_windowEventHandler = windowEventHandler;
}

void WindowSequenceService::initialize()
{
    m_windowEventHandler->addEventListener(m_windowClosedAction);
}

void WindowSequenceService::onWindowClosedEvent(const sf::Event::Closed* closedEvent)
{
    m_window->close();  
}
