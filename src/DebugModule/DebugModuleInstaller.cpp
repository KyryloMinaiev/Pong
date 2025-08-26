#include "DebugModuleInstaller.h"

#include "FPSCounter.h"
#include "../Core/DIContainer/Container.h"

void DebugModuleInstaller::install(Container* container)
{
#if _DEBUG
    container->bind<FPSCounter>().registerType();
#endif
}

DebugModuleInstaller::~DebugModuleInstaller() = default;
