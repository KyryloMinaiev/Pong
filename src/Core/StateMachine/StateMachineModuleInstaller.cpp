module StateMachineModuleInstaller;

import ApplicationStateMachine;

void StateMachineModuleInstaller::install(Container* container)
{
    container->bind<ApplicationStateMachine>().registerType();
}

StateMachineModuleInstaller::~StateMachineModuleInstaller() = default;
