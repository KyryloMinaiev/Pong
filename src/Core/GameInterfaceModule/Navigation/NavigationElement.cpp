#include "SFML/SFMLImport.h"

module NavigationElement;

NavigationDirection getOppositeDirection(NavigationDirection direction)
{
    switch (direction)
    {
    case NavigationDirection::UP:
        return NavigationDirection::DOWN;
    case NavigationDirection::DOWN:
        return NavigationDirection::UP;
    case NavigationDirection::LEFT:
        return NavigationDirection::RIGHT;
    case NavigationDirection::RIGHT:
        return NavigationDirection::LEFT;
    default:
        return NavigationDirection::MAX;       
    }
}

NavigationElement* NavigationNeighbors::getNeighbor(NavigationDirection direction) const
{
    return neighbors[static_cast<int>(direction)];
}

void NavigationNeighbors::setNeighbor(NavigationDirection direction, NavigationElement* neighbor)
{
    neighbors[static_cast<int>(direction)] = neighbor;
}

void NavigationNeighbors::clearNeighbors()
{
    for (auto& element : neighbors)
    {
        element = nullptr;
    }
}

NavigationElement::NavigationElement(UIObject* uiObject) : m_uiObject(uiObject), m_focusable(dynamic_cast<IFocusable*>(
                                                               uiObject)),
                                                           m_interactable(dynamic_cast<IInteractable*>(
                                                               uiObject))
{
}

NavigationElement* NavigationElement::getNeighbor(NavigationDirection direction) const
{
    return m_neighbors.getNeighbor(direction);
}

bool NavigationElement::neighborExists(const NavigationElement* element) const
{
    if (!element)
    {
        return false;
    }
    
    for (auto& neighbor : m_neighbors.neighbors)
    {
        if (neighbor == element)
        {
            return true;
        }   
    }

    return false;  
}

void NavigationElement::setNeighbor(NavigationDirection direction, NavigationElement* neighbor)
{
    m_neighbors.setNeighbor(direction, neighbor);
}

void NavigationElement::clearNeighbors()
{
    m_neighbors.clearNeighbors();
}

IFocusable* NavigationElement::getFocusable() const
{
    return m_focusable;
}

IInteractable* NavigationElement::getInteractable() const
{
    return m_interactable;
}

UIObject* NavigationElement::getUIObject() const
{
    return m_uiObject;
}

sf::Vector2f NavigationElement::getPosition() const
{
    return m_position;
}

bool NavigationElement::positionChanged()
{
    auto newPosition = m_uiObject->getPosition();
    if (newPosition != m_position)
    {
        m_position = newPosition;
        return true;
    }

    return false;   
}
