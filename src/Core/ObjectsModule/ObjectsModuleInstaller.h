#pragma once

#include "../DIContainer/IInstaller.h"

class ObjectsModuleInstaller : public IInstaller<ObjectsModuleInstaller>
{
public:
    void install(Container* container) override;
    ~ObjectsModuleInstaller() override;
};
