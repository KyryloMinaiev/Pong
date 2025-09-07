module BootState;
BootState::~BootState() = default;

import EnterNameState;

void BootState::inject(ApplicationStateMachine* stateMachine)
{
    m_stateMachine = stateMachine;
}

void BootState::enterState()
{
    m_stateMachine->enterState<EnterNameState>();
}

void BootState::exitState()
{
}
