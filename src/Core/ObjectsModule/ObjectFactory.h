#pragma once

class ObjectsContainer;

class ObjectFactory
{
public:
    ObjectFactory() = default;
    virtual ~ObjectFactory() = default;
    void inject(ObjectsContainer* objects_container);

private:
    ObjectsContainer* m_objects_container;
};
