#include "SFML/SFMLImport.h"

export module WindowEventHandler;

import DIContainer;
import Delegates;
import <typeindex>;
import <unordered_map>;
import <memory>;

export class WindowEventHandler : public IUpdatable
{
public:
    ~WindowEventHandler() override = default;

    void inject(sf::RenderWindow* window);

    template<typename TEvent>
    void addEventListener(const Action<const TEvent*>& listener);
    template<typename TEvent>
    void removeEventListener(const Action<const TEvent*>& listener);

    void update(float deltaTime) override;
private:
    void handleEvent(const sf::Event& event) const;
    template<typename TEvent>
    void eventHandler(const sf::Event& event);

    sf::RenderWindow* m_window;
    std::unordered_map<std::type_index, Action<const sf::Event&>> m_eventHandlers;
    std::unordered_map<std::type_index, std::shared_ptr<void>> m_eventListenersMap;
};

template <typename TEvent>
void WindowEventHandler::addEventListener(const Action<const TEvent*>& listener)
{
    std::type_index index = typeid(TEvent);
    if (!m_eventHandlers.contains(index))
    {
        m_eventHandlers[index] = CreateAction(this, &WindowEventHandler::eventHandler<TEvent>);
    }

    if (!m_eventListenersMap.contains(index))
    {
        m_eventListenersMap[index] = std::make_shared<Event<const TEvent*>>();
    }

    auto eventListener = static_cast<Event<const TEvent*>*>(m_eventListenersMap[index].get());
    eventListener->addListener(listener);
}

template <typename TEvent>
void WindowEventHandler::removeEventListener(const Action<const TEvent*>& listener)
{
    std::type_index index = typeid(TEvent);
    if (!m_eventListenersMap.contains(index))
    {
        return;
    }

    auto eventListener = static_cast<Event<const TEvent*>*>(m_eventListenersMap[index].get());
    eventListener->removeListener(listener);
}

template <typename TEvent>
void WindowEventHandler::eventHandler(const sf::Event& event)
{
    std::type_index index = typeid(TEvent);
    const TEvent* eventType = event.getIf<TEvent>();
    if (m_eventListenersMap.contains(index) && eventType)
    {
        auto eventListener = static_cast<Event<const TEvent*>*>(m_eventListenersMap[index].get());
        eventListener->invoke(eventType);
    }
}
