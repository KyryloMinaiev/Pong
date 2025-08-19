#include "Container.h"

Container::Container()
{
    m_registeredTypesMap[typeid(Container).hash_code()] = this;
}
