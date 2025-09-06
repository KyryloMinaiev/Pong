module GlobalInstaller;

import WindowEventHandler;
import WindowSequenceService;
import ResourceManagement;
import DebugModule;
import InputManagement;
import GameInterfaceModule;

void GlobalInstaller::install(Container* container)
{
    container->install<ResourceManagementInstaller>();
    container->bind<WindowEventHandler>().registerType();
    container->bind<WindowSequenceService>().registerType();
    container->bind<InputManager>().asType<IInputManager>().registerType();
    container->install<GameInterfaceModuleInstaller>();

    container->install<DebugModuleInstaller>();
}

GlobalInstaller::~GlobalInstaller() = default;
