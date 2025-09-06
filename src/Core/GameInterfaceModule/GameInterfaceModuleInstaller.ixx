export module GameInterfaceModuleInstaller;

import DIContainer;

export class GameInterfaceModuleInstaller : public IInstaller<GameInterfaceModuleInstaller>
{
public:
    void install(Container* container) override;
    ~GameInterfaceModuleInstaller() override;
};
