module DebugModuleInstaller;

import FPSCounter;

void DebugModuleInstaller::install(Container* container)
{
#if _DEBUG
    container->bind<FPSCounter>().registerType();
#endif
}

DebugModuleInstaller::~DebugModuleInstaller() = default;
