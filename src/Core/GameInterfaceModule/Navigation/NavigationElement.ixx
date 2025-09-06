#include "SFML/SFMLImport.h"

export module NavigationElement;
import <cstdint>;

import UIObject;
import IFocusable;
import IInteractable;

export enum class NavigationDirection : std::uint8_t
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,

    MAX = 4
};

export NavigationDirection getOppositeDirection(NavigationDirection direction);

export struct NavigationElement;

export struct NavigationNeighbors
{
    NavigationElement* neighbors[static_cast<int>(NavigationDirection::MAX)];
    NavigationElement* getNeighbor(NavigationDirection direction) const;
    void setNeighbor(NavigationDirection direction, NavigationElement* neighbor);
    void clearNeighbors();
};

export struct NavigationElement
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
