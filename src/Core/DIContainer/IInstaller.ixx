export module IInstaller;

import ContainerType;

export template <typename TInstaller>
class IInstaller
{
public:
    virtual ~IInstaller() = default;
    virtual void install(Container* container) = 0;
};