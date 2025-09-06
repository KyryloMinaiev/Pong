#include "SFML/SFMLImport.h"

export module GameInterface;

import <set>;
import <string>;
import UIObject;
import DIContainer;
import ObjectsModule;
import NavigationService;
import Delegates;

export class GameInterface
{
public:
    GameInterface();
    virtual ~GameInterface() = default;
    void inject(sf::RenderWindow* window, Container* container, ObjectsContainer* objectsContainer,
                NavigationService* navigationService);
    void render() const;
    template <typename TUIObject>
        requires std::is_base_of_v<UIObject, TUIObject>
    TUIObject* createUIObjectOfType(const std::string& name = "UIObject");

private:
    void onUIObjectActiveChanged(UIObject* object, bool isActive);
    Action<UIObject*, bool> m_objectActiveAction;

    std::set<UIObject*> m_activeObjects;
    sf::RenderWindow* m_window;
    Container* m_container;
    ObjectsContainer* m_objectsContainer;
    NavigationService* m_navigationService;
};

template <typename TUIObject>
    requires std::is_base_of_v<UIObject, TUIObject>
TUIObject* GameInterface::createUIObjectOfType(const std::string& name)
{
    TUIObject* ptr = m_container->instantiate<TUIObject>(name, false);
    ptr->addActiveChangedListener(m_objectActiveAction);
    m_objectsContainer->setObjectActive(ptr, true);
    return ptr;
}
