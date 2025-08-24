#pragma once
#include <SFML/Graphics/RenderWindow.hpp>


#include "../Core/DIContainer/Container.h"
#include "IFocusable.h"
#include "IInteractable.h"
#include "UIObject.h"

class GameInterface
{
public:
    virtual ~GameInterface() = default;
    void inject(sf::RenderWindow* window, Container* container);
    void render() const;
    template <typename TUIObject>
    requires std::is_base_of_v<UIObject, TUIObject>
    TUIObject* createUIObjectOfType(const std::string& name = "UIObject");
    //void destroyUIObject(UIObject* object);
private:
    std::vector<UIObject*> m_uiObjects;
    
    sf::RenderWindow* m_window;
    Container* m_container;
};

template <typename TUIObject>
requires std::is_base_of_v<UIObject, TUIObject>
TUIObject* GameInterface::createUIObjectOfType(const std::string& name)
{
    TUIObject* ptr = m_container->instantiate<TUIObject>(name);
    m_uiObjects.push_back(ptr);
    return ptr;
}
