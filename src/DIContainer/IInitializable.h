#pragma once

class IInitializable
{
public:
    virtual ~IInitializable() = default;
    virtual void initialize() = 0;
};
