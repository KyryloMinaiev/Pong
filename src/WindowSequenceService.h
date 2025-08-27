#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Core/DIContainer/IInitializable.h"
#include "WindowEvents/WindowEventHandler.h"

class WindowSequenceService : public IInitializable
{
public:
    WindowSequenceService();
    ~WindowSequenceService() override;
    void inject(sf::RenderWindow* window, WindowEventHandler* windowEventHandler);
    void initialize() override;

private:
    void onWindowClosedEvent(const sf::Event::Closed* closedEvent);
    
    sf::RenderWindow* m_window;
    WindowEventHandler* m_windowEventHandler;

    Action<const sf::Event::Closed*> m_windowClosedAction;
};
