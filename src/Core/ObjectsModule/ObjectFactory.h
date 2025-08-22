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
    requires std::is_base_of_v<TObject, Object>
    TObject* createObjectOfType();

    template<typename TObject>
    requires std::is_base_of_v<TObject, Object>
    TObject* createObjectOfType(const std::string& name);
private:
    ObjectsContainer* m_objects_container;
};

template <typename TObject> requires std::is_base_of_v<TObject, Object>
TObject* ObjectFactory::createObjectOfType()
{
    return createObjectOfType<TObject>("New Object");   
}

template <typename TObject> requires std::is_base_of_v<TObject, Object>
TObject* ObjectFactory::createObjectOfType(const std::string& name)
{
    auto object_ptr = std::make_shared<TObject>();
    object_ptr->name = name;
    m_objects_container->addObject(object_ptr);
    return object_ptr.get();  
}
