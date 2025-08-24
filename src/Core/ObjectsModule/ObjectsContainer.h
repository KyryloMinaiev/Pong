#pragma once
#include <memory>
#include <vector>

#include "Object.h"

class ObjectsContainer
{
public:
    virtual ~ObjectsContainer() = default;

    void addObject(const std::shared_ptr<Object>& object);
    std::vector<std::shared_ptr<Object>>& getObjects();
private:
    std::vector<std::shared_ptr<Object>> m_objects;
};
