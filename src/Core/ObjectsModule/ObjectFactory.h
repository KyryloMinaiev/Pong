#pragma once
#include <memory>
#include <type_traits>

#include "Object.h"
#include "ObjectsContainer.h"

class ObjectsContainer;

class ObjectFactory
{
public:
    ObjectFactory() = default;
    virtual ~ObjectFactory() = default;
    void inject(ObjectsContainer* objects_container);

    template<typename TObject>
    requires std::is_base_of_v<Object, TObject>
    TObject* createObjectOfType();

    template<typename TObject>
    requires std::is_base_of_v<Object, TObject>
    TObject* createObjectOfType(const std::string& name);
private:
    ObjectsContainer* m_objects_container;
};

template <typename TObject> requires std::is_base_of_v<Object, TObject>
TObject* ObjectFactory::createObjectOfType()
{
    return createObjectOfType<TObject>("New Object");   
}

template <typename TObject> requires std::is_base_of_v<Object, TObject>
TObject* ObjectFactory::createObjectOfType(const std::string& name)
{
    auto object_ptr = std::make_shared<TObject>();
    object_ptr->name = name;
    object_ptr->setActive(true);
    m_objects_container->addObject(object_ptr);
    return object_ptr.get();  
}
