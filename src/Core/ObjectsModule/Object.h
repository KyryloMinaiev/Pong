#pragma once
#include <string>
#include <vector>

class Object
{
public:
    virtual ~Object() = default;

    bool isActive() const;
    std::vector<Object*>& getChildren();
    
    std::string name;
protected:
    virtual void onEnable();
    virtual void onUpdate(float deltaTime);
    virtual void onDisable();
    
    bool m_active;
    std::vector<Object*> m_children;
    Object* m_parent;
};
