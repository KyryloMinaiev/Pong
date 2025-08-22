#pragma once

class Container;

template <typename TInstaller>
class IInstaller
{
public:
    virtual ~IInstaller() = default;
    virtual void install(Container* container) = 0;
};
