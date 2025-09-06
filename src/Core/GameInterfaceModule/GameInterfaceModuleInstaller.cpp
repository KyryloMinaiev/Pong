module GameInterfaceModuleInstaller;

import NavigationService;
import IFontsProvider;
import FontsProvider;
import GameInterface;
import ButtonFactory;
import ImageFactory;
import IButtonFactory;
import IImageFactory;
import ITextFactory;
import TextFactory;

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
