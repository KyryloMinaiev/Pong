#include "GlobalInstaller.h"

#include "Core/DIContainer/Container.h"
#include "Core/ObjectsModule/ObjectsModuleInstaller.h"

void GlobalInstaller::install(Container* container)
{
    container->install<ObjectsModuleInstaller>();
}

GlobalInstaller::~GlobalInstaller() = default;
