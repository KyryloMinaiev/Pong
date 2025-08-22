#pragma once
#include <string>
#include <vector>

class Object
{
public:
    virtual ~Object() = default;

    void setActive(bool active);
    void setParent(Object* parent);

    std::vector<Object*>& getChildren();
    
    std::string name;
protected:
    virtual void onEnable();
    virtual void onDisable();
    
    bool m_active;
    std::vector<Object*> m_children;
    Object* m_parent;
};
