export module Event;

import <vector>;
import Action;

export template <typename... Args>
class Event
{
public:
    Event() = default;
    ~Event() = default;

    void addListener(const Action<Args...>& listener);
    void removeListener(const Action<Args...>& listener);
    void invoke(Args... args) const;
    void operator()(Args... args) const;
private:
    std::vector<Action<Args...>> m_listeners;
};

template <typename ... Args>
void Event<Args...>::addListener(const Action<Args...>& listener)
{
    m_listeners.push_back(listener);   
}

template <typename ... Args>
void Event<Args...>::removeListener(const Action<Args...>& listener)
{
    m_listeners.erase(std::remove(m_listeners.begin(), m_listeners.end(), listener), m_listeners.end());  
}

template <typename ... Args>
void Event<Args...>::invoke(Args... args) const
{
    for (const auto& listener : m_listeners)
    {
        listener(args...);
    }  
}

template <typename ... Args>
void Event<Args...>::operator()(Args... args) const
{
    invoke(args...); 
}
