#include "GameInterfaceModuleInstaller.h"

#include "Navigation/NavigationService.h"
#include "FontsProvider.h"
#include "GameInterface.h"
#include "../Core/DIContainer/Container.h"
#include "Button/ButtonFactory.h"
#include "Image/ImageFactory.h"
#include "Text/TextFactory.h"

void GameInterfaceModuleInstaller::install(Container* container)
{
    container->bind<NavigationService>().registerType();
    container->bind<GameInterface>().registerType();
    container->bind<FontsProvider>().asType<IFontsProvider>().registerType();
    container->bind<TextFactory>().asType<ITextFactory>().registerType();
    container->bind<ImageFactory>().asType<IImageFactory>().registerType();
    container->bind<ButtonFactory>().asType<IButtonFactory>().registerType(); 
}

GameInterfaceModuleInstaller::~GameInterfaceModuleInstaller() = default;
