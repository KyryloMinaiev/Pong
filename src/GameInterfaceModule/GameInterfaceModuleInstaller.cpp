#include "GameInterfaceModuleInstaller.h"

#include "FontsProvider.h"
#include "GameInterface.h"
#include "../Core/DIContainer/Container.h"
#include "Text/TextFactory.h"

void GameInterfaceModuleInstaller::install(Container* container)
{
    container->bind<GameInterface>().registerType();
    container->bind<FontsProvider>().asType<IFontsProvider>().registerType();
    container->bind<TextFactory>().asType<ITextFactory>().registerType();  
}

GameInterfaceModuleInstaller::~GameInterfaceModuleInstaller() = default;
