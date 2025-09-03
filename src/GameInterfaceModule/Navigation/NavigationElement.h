#pragma once
#include <cstdint>
#include <SFML/System/Vector2.hpp>

class UIObject;
class IInteractable;
class IFocusable;

enum class NavigationDirection : std::uint8_t
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,

    MAX = 4
};

NavigationDirection getOppositeDirection(NavigationDirection direction);

struct NavigationElement;

struct NavigationNeighbors
{
    NavigationElement* neighbors[static_cast<int>(NavigationDirection::MAX)];
    NavigationElement* getNeighbor(NavigationDirection direction) const;
    void setNeighbor(NavigationDirection direction, NavigationElement* neighbor);
    void clearNeighbors();
};

struct NavigationElement
{
private:
    UIObject* m_uiObject;
    IFocusable* m_focusable;
    IInteractable* m_interactable;
    NavigationNeighbors m_neighbors;
    sf::Vector2f m_position;

public:
    NavigationElement(UIObject* uiObject);
    
    NavigationElement* getNeighbor(NavigationDirection direction) const;
    bool neighborExists(const NavigationElement* element) const;
    void setNeighbor(NavigationDirection direction, NavigationElement* neighbor);
    void clearNeighbors();
    
    IFocusable* getFocusable() const;
    IInteractable* getInteractable() const;
    UIObject* getUIObject() const;
    sf::Vector2f getPosition() const;
    bool positionChanged();
};
