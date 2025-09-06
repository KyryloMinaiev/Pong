export module UIObject;

import Delegates;
import IRenderable;
import ObjectsModule;

export class UIObject : public TransformableObject, public IRenderable
{
public:
    friend class GameInterface;
    ~UIObject() override;

protected:
    void onEnable() override;
    void onDisable() override;
private:
    Event<UIObject*, bool> m_activeChangedEvent;
    void addActiveChangedListener(const Action<UIObject*, bool>& onActiveChangedListener);
};
