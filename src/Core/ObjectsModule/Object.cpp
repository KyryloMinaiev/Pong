#include "Object.h"

void Object::setActive(bool active)
{
    if (active == m_active)
    {
        return;
    }

    m_active = active;
    if (m_active)
    {
        onEnable();
    }
    else
    {
        onDisable();
    }   
}

void Object::onEnable() { }

void Object::onDisable() { }
