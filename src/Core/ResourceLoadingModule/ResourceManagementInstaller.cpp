module ResourceManagementInstaller;

import ITextureContainer;
import TextureContainer;

void ResourceManagementInstaller::install(Container* container)
{
    container->bind<TextureContainer>().asType<ITextureContainer>().registerType();
}

ResourceManagementInstaller::~ResourceManagementInstaller() = default;
