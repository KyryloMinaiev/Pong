export module ObjectFactory;

import Object;
import ObjectsContainer;

import <memory>;
import <type_traits>;
import <string>;

export class ObjectFactory
{
public:
    ObjectFactory(ObjectsContainer* container);
    virtual ~ObjectFactory() = default;

    template <typename TObject>
        requires std::is_base_of_v<Object, TObject>
    TObject* createObjectOfType(const std::string& name = "New Object", bool active = true);

private:
    ObjectsContainer* m_objectsContainer;
};

template <typename TObject> requires std::is_base_of_v<Object, TObject>
TObject* ObjectFactory::createObjectOfType(const std::string& name, bool active)
{
    auto object_ptr = std::make_shared<TObject>();
    m_objectsContainer->addObject(object_ptr);
    object_ptr->name = name;
    m_objectsContainer->setObjectActive(object_ptr.get(), active);
    return object_ptr.get();
}
