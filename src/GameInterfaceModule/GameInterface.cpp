#include "GameInterface.h"

void GameInterface::inject(sf::RenderWindow* window, Container* container)
{
    m_window = window;
    m_container = container;
}

void GameInterface::render() const
{
    for (auto uiObject : m_uiObjects)
    {
        if (uiObject->isActive())
        {
            m_window->draw(*uiObject->getDrawable());
        }
    }
}
