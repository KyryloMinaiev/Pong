export module BootState;

import StateMachineModule;

export class BootState : public ApplicationState
{
public:
    ~BootState() override;
    void inject(ApplicationStateMachine* stateMachine);
    void enterState() override;
    void exitState() override;
private:
    ApplicationStateMachine* m_stateMachine;
};
