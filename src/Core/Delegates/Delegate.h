#pragma once

#include <functional>

template <typename Signature>
class Delegate;

template <typename Tout, typename... Args>
class Delegate<Tout(Args...)>
{
public:
    Delegate() = default;

    template <class T>
    Delegate(T* instance, Tout (T::*method)(Args...))
    {
        Bind(instance, method);
    }

    template <typename T>
    void Bind(T* instance, Tout (T::*method)(Args...))
    {
        m_owner = instance;
        m_method = method;
        
        m_function = [instance, method](Args... args) -> Tout
        {
            return (instance->*method)(args...);
        };
    }

    void Bind(std::function<Tout(Args...)> func)
    {
        m_function = std::move(func);
    }

    Tout Invoke(Args... args) const
    {
        if (m_function)
        {
            return m_function(std::forward<Args>(args)...);
        }
        else
        {
            throw std::bad_function_call();
        }
    }

    Tout operator()(Args... args) const
    {
        return Invoke(std::forward<Args>(args)...);
    }

    bool operator ==(const Delegate& other) const
    {
        if (m_owner == nullptr || other.m_owner == nullptr)
        {
            return m_owner == other.m_owner;
        }
        
        return m_owner == other.m_owner && 
               m_method == other.m_method && 
               m_function.target_type() == other.m_function.target_type();

    }

private:
    void* m_owner;
    void* m_method;
    std::function<Tout(Args...)> m_function;
};

template <typename T, typename Tout, typename... Args>
Delegate<Tout(Args...)> CreateDelegate(T* instance, Tout (T::*method)(Args...))
{
    return Delegate<Tout(Args...)>(instance, method);
}

template <typename T, typename Tout, typename... Args>
Delegate<Tout(Args...)> CreateDelegate(T* instance, Tout (T::*method)(Args...) const)
{
    return Delegate<Tout(Args...)>(instance, method);
}
