#include "ObjectsContainer.h"

void ObjectsContainer::addObject(const std::shared_ptr<Object>& object)
{
    m_objects.push_back(object);  
}
