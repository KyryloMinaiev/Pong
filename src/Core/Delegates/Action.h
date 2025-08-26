#pragma once

#include "Delegate.h"

template <typename... Args>
using Action = Delegate<void(Args...)>;

template <typename T, typename... Args>
Action<Args...> CreateAction(T* instance, void (T::*method)(Args...))
{
    return Action<Args...>(instance, method);
}

template <typename T, typename... Args>
Action<Args...> CreateAction(T* instance, void (T::*method)(Args...) const)
{
    return Action<Args...>(instance, method);
}
