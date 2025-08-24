#include "GlobalInstaller.h"

#include "TextureContainer.h"
#include "Core/DIContainer/Container.h"
#include "Core/ObjectsModule/ObjectsModuleInstaller.h"
#include "DebugModule/DebugModuleInstaller.h"
#include "GameInterfaceModule/GameInterfaceModuleInstaller.h"

void GlobalInstaller::install(Container* container)
{
    container->bind<TextureContainer>().asType<ITextureContainer>().registerType();
    container->install<ObjectsModuleInstaller>();
    container->install<GameInterfaceModuleInstaller>();

    container->install<DebugModuleInstaller>();
}

GlobalInstaller::~GlobalInstaller() = default;
