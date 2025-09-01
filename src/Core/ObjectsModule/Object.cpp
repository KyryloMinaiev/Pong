#include "Object.h"

bool Object::isActive() const
{
    return m_active;
}

std::vector<Object*>& Object::getChildren()
{
    return m_children;
}

void Object::onEnable() { }

void Object::onUpdate(float deltaTime){ }

void Object::onDisable() { }
