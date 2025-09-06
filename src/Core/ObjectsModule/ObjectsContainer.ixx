export module ObjectsContainer;

import Object;
import <memory>;
import <set>;
import <vector>;

export class ObjectsContainer
{
public:
    virtual ~ObjectsContainer() = default;
    void update(float deltaTime) const;
    void addObject(const std::shared_ptr<Object>& object);
    void setObjectActive(Object* obj, bool active);
    void setObjectParent(Object* parent, Object* child);
    void destroyObject(Object* object);
private:
    void setObjectActiveInternal(Object* obj, bool active);
    
    std::set<std::shared_ptr<Object>> m_objects;
    std::vector<Object*> m_activeObjects;
};
