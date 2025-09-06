export module GlobalInstaller;

import DIContainer;

export class GlobalInstaller : public IInstaller<GlobalInstaller>
{
public:
    void install(Container* container) override;
    ~GlobalInstaller() override;
};
