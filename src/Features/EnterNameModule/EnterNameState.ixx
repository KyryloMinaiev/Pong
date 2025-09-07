export module EnterNameState;

import StateMachineModule;

export class EnterNameState : public ApplicationState
{
public:
    ~EnterNameState() override;
    void enterState() override;
    void exitState() override;
};
