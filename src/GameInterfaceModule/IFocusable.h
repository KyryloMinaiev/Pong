#pragma once

class IFocusable
{
public:
    virtual ~IFocusable() = default;
    void focus();
    void unfocus();
};
