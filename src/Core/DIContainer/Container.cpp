#include "Container.h"

Container::Container()
{
    m_registeredTypesMap[typeid(Container).hash_code()] = this;
}

void Container::setupObjectsFactory(ObjectFactory* factory)
{
    m_objectFactory = factory;
}

void Container::update(float deltaTime) const
{
    for (auto& updatable : m_updatables)
    {
        updatable->update(deltaTime);       
    }
}

void Container::tryAddType(size_t typeHash, const std::string& typeName, void* value)
{
    if (m_registeredTypesMap.contains(typeHash))
    {
        std::cout << "Type " << typeName << " already registered!" << std::endl;
    }
    else
    {
        m_registeredTypesMap[typeHash] = value;
    }
}
