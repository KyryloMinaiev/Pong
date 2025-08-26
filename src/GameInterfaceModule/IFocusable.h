#pragma once

class IFocusable
{
public:
    virtual ~IFocusable() = default;
    virtual void focus() = 0;
    virtual void unfocus() = 0;
};
