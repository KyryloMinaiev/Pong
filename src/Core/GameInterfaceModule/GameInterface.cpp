module GameInterface;

GameInterface::GameInterface()
{
    m_objectActiveAction = CreateAction(this, &GameInterface::onUIObjectActiveChanged);
}

void GameInterface::inject(sf::RenderWindow* window, Container* container, ObjectsContainer* objectsContainer,
                NavigationService* navigationService)
{
    m_window = window;
    m_container = container;
    m_objectsContainer = objectsContainer;
    m_navigationService = navigationService;
}

void GameInterface::render() const
{
    for (auto uiObject : m_activeObjects)
    {
        m_window->draw(*uiObject->getDrawable());
    }
}

void GameInterface::onUIObjectActiveChanged(UIObject* object, bool isActive)
{
    if (isActive && !m_activeObjects.contains(object))
    {
        m_activeObjects.insert(object);
        m_navigationService->insertUIObject(object);
    }

    if (!isActive && m_activeObjects.contains(object))
    {
        m_activeObjects.erase(object);
        m_navigationService->removeUIObject(object);
    }
}
