#pragma once

class IInteractable
{
public:
    virtual ~IInteractable() = default;
    virtual void beginInteraction() = 0;
    virtual void endInteraction() = 0;
};
