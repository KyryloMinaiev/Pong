#pragma once
#include <string>
#include <vector>

class Object
{
public:
    friend class ObjectsContainer;
    
    virtual ~Object() = default;

    bool isActive() const;
    std::vector<Object*>& getChildren();
    Object* getParent() const;
    
    std::string name;
protected:
    virtual void onEnable();
    virtual void onUpdate(float deltaTime);
    virtual void onDisable();
    
    bool m_active;
    std::vector<Object*> m_children;
    Object* m_parent;
};
