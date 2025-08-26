#pragma once
#include "../Core/DIContainer/IInstaller.h"

class GameInterfaceModuleInstaller : public IInstaller<GameInterfaceModuleInstaller>
{
public:
    void install(Container* container) override;
    ~GameInterfaceModuleInstaller() override;
};
