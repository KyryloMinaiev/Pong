#pragma once
#include <string>

class Object
{
public:
    virtual ~Object() = default;

    void setActive(bool active);

    std::string name;
protected:
    virtual void onEnable();
    virtual void onDisable();
private:
    bool m_active;
};
