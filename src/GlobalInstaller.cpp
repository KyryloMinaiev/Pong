module GlobalInstaller;

import WindowEventHandler;
import WindowSequenceService;
import ResourceManagement;
import DebugModule;
import InputManagement;
import GameInterfaceModule;
import StateMachineModule;
import EnterNameModuleInstaller;
import BootState;

void GlobalInstaller::install(Container* container)
{
    container->install<ResourceManagementInstaller>();
    container->bind<WindowEventHandler>().registerType();
    container->bind<WindowSequenceService>().registerType();
    container->bind<InputManager>().asType<IInputManager>().registerType();
    container->install<GameInterfaceModuleInstaller>();
    container->install<StateMachineModuleInstaller>();
    
    container->install<EnterNameModuleInstaller>();
    
    container->install<DebugModuleInstaller>();

    container->bind<BootState>().registerType();
}

GlobalInstaller::~GlobalInstaller() = default;
