#pragma once
#include "Core/DIContainer/IInstaller.h"

class GlobalInstaller : public IInstaller<GlobalInstaller>
{
public:
    void install(Container* container) override;
    ~GlobalInstaller() override;
};
