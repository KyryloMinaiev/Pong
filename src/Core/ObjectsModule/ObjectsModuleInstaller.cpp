#include "ObjectsModuleInstaller.h"

#include "ObjectFactory.h"
#include "ObjectsContainer.h"
#include "../DIContainer/Container.h"

void ObjectsModuleInstaller::install(Container* container)
{
    container->bind<ObjectsContainer>().registerType();
    container->bind<ObjectFactory>().registerType();

    container->setupObjectsFactory(container->resolve<ObjectFactory>());
}

ObjectsModuleInstaller::~ObjectsModuleInstaller() = default;
