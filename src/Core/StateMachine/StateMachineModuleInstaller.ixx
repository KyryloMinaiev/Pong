export module StateMachineModuleInstaller;

import DIContainer;

export class StateMachineModuleInstaller : public IInstaller<StateMachineModuleInstaller>
{
public:
    void install(::Container* container) override;
    ~StateMachineModuleInstaller() override;
};
