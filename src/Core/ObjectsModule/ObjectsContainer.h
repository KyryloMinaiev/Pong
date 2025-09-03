#pragma once
#include <memory>
#include <set>

#include "Object.h"
#include "../DIContainer/IUpdatable.h"

class ObjectsContainer : public IUpdatable
{
public:
    virtual ~ObjectsContainer() = default;
    void update(float deltaTime) override;
    void addObject(const std::shared_ptr<Object>& object);
    void setObjectActive(Object* obj, bool active);
    void setObjectParent(Object* parent, Object* child);
    void destroyObject(Object* object);
private:
    void setObjectActiveInternal(Object* obj, bool active);
    
    std::set<std::shared_ptr<Object>> m_objects;
    std::vector<Object*> m_activeObjects;
};
