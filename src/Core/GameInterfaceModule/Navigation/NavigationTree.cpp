module NavigationTree;

NavigationTree::~NavigationTree() = default;

void NavigationTree::moveNavigation(NavigationDirection direction)
{
    if (!m_current)
    {
        return;
    }

    if (const auto next = m_current->getNeighbor(direction))
    {
        updateCurrentElement(next);
    }
}

void NavigationTree::addNavigationElement(UIObject* uiObject)
{
    NavigationElement element(uiObject);
    if (element.getFocusable())
    {
        m_navigationElements.push_back(element);
        m_dirty = true;
    }
}

void NavigationTree::removeNavigationElement(UIObject* uiObject)
{
    const auto it = std::find_if(m_navigationElements.begin(), m_navigationElements.end(),
                                 [uiObject](const NavigationElement& element)
                                 {
                                     return element.getUIObject() == uiObject;
                                 });

    if (it == m_navigationElements.end())
    {
        return;
    }

    if (auto element = &*it; element == m_current)
    {
        findNextElement();
    }

    m_navigationElements.erase(it);
    m_dirty = true;
}

void NavigationTree::update()
{
    checkElementsPositions();

    if (m_dirty)
    {
        reconstructTree();
    }
}

void NavigationTree::checkElementsPositions()
{
    for (auto element : m_navigationElements)
    {
        m_dirty |= element.positionChanged();
    }
}

void NavigationTree::reconstructTree()
{
    if (m_navigationElements.empty())
    {
        return;
    }

    for (auto& element : m_navigationElements)
    {
        element.clearNeighbors();
    }

    for (auto& element : m_navigationElements)
    {
        for (int i = static_cast<int>(NavigationDirection::UP); i < static_cast<int>(NavigationDirection::MAX); ++i)
        {
            NavigationDirection direction = static_cast<NavigationDirection>(i);
            if (NavigationElement* neighbor = getClosestElement(&element, direction))
            {
                element.setNeighbor(direction, neighbor);
                neighbor->setNeighbor(getOppositeDirection(direction), &element);
            }
        }
    }
}

void NavigationTree::updateCurrentElement(NavigationElement* element)
{
    if (m_current != element)
    {
        m_current = element;
        onNavigationElementChanged.invoke(m_current);
    }
}

void NavigationTree::findNextElement()
{
    if (!m_current)
    {
        return;
    }

    NavigationElement* next = nullptr;
    for (int i = static_cast<int>(NavigationDirection::UP); i < static_cast<int>(NavigationDirection::MAX); ++i)
    {
        NavigationDirection direction = static_cast<NavigationDirection>(i);
        if (next = m_current->getNeighbor(direction))
        {
            break;
        }
    }

    updateCurrentElement(next);
}

NavigationElement* NavigationTree::getClosestElement(const NavigationElement* current, NavigationDirection direction)
{
    if (!current)
    {
        return nullptr;
    }

    NavigationElement* closest = nullptr;
    for (auto& element : m_navigationElements)
    {
        if (&element == current || current->neighborExists(&element))
        {
            continue;
        }

        if (isElementInDirection(element, *current, direction))
        {
            closest = &element;
        }

    }

    return closest;
}

bool NavigationTree::isElementInDirection(const NavigationElement& element,
                                          const NavigationElement& current,
                                          NavigationDirection direction)
{
    switch (direction)
    {
    case NavigationDirection::UP:
        return element.getPosition().y < current.getPosition().y;
    case NavigationDirection::DOWN:
        return element.getPosition().y > current.getPosition().y;
    case NavigationDirection::LEFT:
        return element.getPosition().x < current.getPosition().x;
    case NavigationDirection::RIGHT:
        return element.getPosition().x > current.getPosition().x;
    default:
        return false;
    }
}
