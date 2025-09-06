#include "SFML/SFMLImport.h"

module WindowEventHandler;

#include <ranges>

void WindowEventHandler::inject(sf::RenderWindow* window)
{
    m_window = window;
}

void WindowEventHandler::update(float deltaTime)
{
    while (const std::optional event = m_window->pollEvent())
    {
        handleEvent(*event);
    }
}

void WindowEventHandler::handleEvent(const sf::Event& event) const
{
    for (const auto& eventHandler : m_eventHandlers | std::views::values)
    {
        eventHandler(event);
    }
}
