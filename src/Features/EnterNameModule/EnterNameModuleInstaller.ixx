export module EnterNameModuleInstaller;

import DIContainer;

export class EnterNameModuleInstaller : public IInstaller<EnterNameModuleInstaller>
{
public:
    void install(::Container* container) override;
    ~EnterNameModuleInstaller() override;
};
