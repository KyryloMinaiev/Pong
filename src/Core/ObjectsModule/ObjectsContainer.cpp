#include "ObjectsContainer.h"

void ObjectsContainer::update(float deltaTime)
{
    for (auto& object : m_objects)
    {
        object->onUpdate(deltaTime);
    }
}

void ObjectsContainer::addObject(const std::shared_ptr<Object>& object)
{
    if (!m_objects.contains(object))
    {
        m_objects.insert(object);
    }
}

void ObjectsContainer::setObjectActive(Object* obj, bool active)
{
    bool previouslyActive = obj->isActive();
    if (previouslyActive == active)
    {
        return;
    }

    setObjectActiveInternal(obj, active);
}

void ObjectsContainer::setObjectParent(Object* parent, Object* child)
{
    if (parent == child)
    {
        return;
    }

    if (Object* previousParent = child->m_parent)
    {
        std::erase(previousParent->m_children, child);
    }

    child->m_parent = parent;
    if (parent)
    {
        parent->getChildren().push_back(child);
        setObjectActive(child, parent->isActive());
    }
}

void ObjectsContainer::destroyObject(Object* object)
{
    setObjectActive(object, false);
    std::erase_if(m_objects, [object](const std::shared_ptr<Object>& objPtr) { return objPtr.get() == object; });
}

void ObjectsContainer::setObjectActiveInternal(Object* obj, bool active)
{
    if (active)
    {
        m_activeObjects.push_back(obj);
        obj->onEnable();
        for (auto& child : obj->getChildren())
        {
            setObjectActiveInternal(child, true);
        }
    }
    else
    {
        std::erase(m_activeObjects, obj);
        obj->onDisable();
        for (auto& child : obj->getChildren())
        {
            setObjectActiveInternal(child, false);
        }
    }

    obj->m_active = active;
}
