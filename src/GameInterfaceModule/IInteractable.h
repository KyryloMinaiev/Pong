#pragma once

class IInteractable
{
public:
    virtual ~IInteractable() = default;
    virtual void interact() = 0;
};
