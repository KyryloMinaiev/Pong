export module Action;

import Delegate;

export template <typename... Args>
using Action = Delegate<void(Args...)>;

export template <typename T, typename... Args>
Action<Args...> CreateAction(T* instance, void (T::*method)(Args...))
{
    return Action<Args...>(instance, method);
}

export template <typename T, typename... Args>
Action<Args...> CreateAction(T* instance, void (T::*method)(Args...) const)
{
    return Action<Args...>(instance, method);
}
