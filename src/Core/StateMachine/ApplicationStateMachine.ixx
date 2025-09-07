export module ApplicationStateMachine;

import DIContainer;
import ApplicationState;
import <typeindex>;
import <unordered_map>;
import <iostream>;

export class ApplicationStateMachine
{
public:
    virtual ~ApplicationStateMachine() = default;
    void inject(Container* container);
    template <class TState>
        requires std::is_base_of_v<ApplicationState, TState>
    void enterState();

private:
    template <class TState>
        requires std::is_base_of_v<ApplicationState, TState>
    ApplicationState* tryGetApplicationState();

    Container* m_container;
    ApplicationState* m_currentState;
    std::unordered_map<std::type_index, ApplicationState*> m_registeredStates;
};

template <class TState> requires std::is_base_of_v<ApplicationState, TState>
void ApplicationStateMachine::enterState()
{
    if (m_currentState)
    {
        m_currentState->exitState();
        m_currentState = nullptr;
    }

    if (auto state = tryGetApplicationState<TState>())
    {
        std::cout << "Entered " << typeid(TState).name() << " state!" << '\n';
        m_currentState = state;
        m_currentState->enterState();
    }
    else
    {
        std::cout << "State " << typeid(TState).name() << " was not found!" << '\n';
    }
}

template <class TState> requires std::is_base_of_v<ApplicationState, TState>
ApplicationState* ApplicationStateMachine::tryGetApplicationState()
{
    auto typeIndex = std::type_index(typeid(TState));
    if (m_registeredStates.contains(typeIndex))
    {
        return m_registeredStates[typeIndex];
    }

    TState* statePtr = m_container->resolve<TState>();
    return dynamic_cast<ApplicationState*>(statePtr);
}
