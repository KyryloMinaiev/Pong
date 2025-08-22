#include "Object.h"

void Object::setActive(bool active)
{
    if (active == m_active)
    {
        return;
    }

    m_active = active;
    for (auto& child : m_children)
    {
        child->setActive(active);       
    }
    
    if (m_active)
    {
        onEnable();
    }
    else
    {
        onDisable();
    }   
}

void Object::setParent(Object* parent)
{
    if (m_parent)
    {
        std::erase(m_parent->m_children, this);       
    }
    
    m_parent = parent;
    if (m_parent)
    {
        m_parent->m_children.push_back(this);
    }
}

std::vector<Object*>& Object::getChildren()
{
    return m_children;
}

void Object::onEnable() { }

void Object::onDisable() { }
