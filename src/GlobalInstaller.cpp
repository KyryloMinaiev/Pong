#include "GlobalInstaller.h"

#include "TextureContainer.h"
#include "WindowSequenceService.h"
#include "Core/DIContainer/Container.h"
#include "Core/ObjectsModule/ObjectsModuleInstaller.h"
#include "DebugModule/DebugModuleInstaller.h"
#include "GameInterfaceModule/GameInterfaceModuleInstaller.h"
#include "InputModule/InputManager.h"
#include "WindowEvents/WindowEventHandler.h"

void GlobalInstaller::install(Container* container)
{
    container->bind<TextureContainer>().asType<ITextureContainer>().registerType();
    container->bind<WindowEventHandler>().registerType();
    container->bind<WindowSequenceService>().registerType();
    container->bind<InputManager>().asType<IInputManager>().registerType();
    container->install<ObjectsModuleInstaller>();
    container->install<GameInterfaceModuleInstaller>();

    container->install<DebugModuleInstaller>();
}

GlobalInstaller::~GlobalInstaller() = default;
