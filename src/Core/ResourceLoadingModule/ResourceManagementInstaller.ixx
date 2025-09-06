export module ResourceManagementInstaller;

import DIContainer;

export class ResourceManagementInstaller : IInstaller<ResourceManagementInstaller>
{
public:
    void install(::Container* container) override;
    ~ResourceManagementInstaller() override;
};
