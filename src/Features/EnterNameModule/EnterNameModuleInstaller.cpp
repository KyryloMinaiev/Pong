module EnterNameModuleInstaller;

import EnterNameState;

void EnterNameModuleInstaller::install(Container* container)
{
    container->bind<EnterNameState>().registerType();
}

EnterNameModuleInstaller::~EnterNameModuleInstaller()
{
}
