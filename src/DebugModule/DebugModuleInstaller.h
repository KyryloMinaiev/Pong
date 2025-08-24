#pragma once

#include "../Core/DIContainer/IInstaller.h"

class DebugModuleInstaller : public IInstaller<DebugModuleInstaller>
{
public:
    void install(Container* container) override;
    ~DebugModuleInstaller() override;
};
