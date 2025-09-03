#include "Object.h"

bool Object::isActive() const
{
    return m_active;
}

std::vector<Object*>& Object::getChildren()
{
    return m_children;
}

Object* Object::getParent() const
{
    return m_parent;
}

void Object::onEnable() { }

void Object::onUpdate(float deltaTime){ }

void Object::onDisable() { }
