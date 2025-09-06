export module DebugModuleInstaller;

import DIContainer;

export class DebugModuleInstaller : public IInstaller<DebugModuleInstaller>
{
public:
    void install(Container* container) override;
    ~DebugModuleInstaller() override;
};
