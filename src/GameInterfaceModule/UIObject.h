#pragma once

#include "../Core/Delegates/Action.h"
#include "../Core/Delegates/Event.h"
#include "../Core/ObjectsModule/TransformableObject.h"
#include "../RenderModule/IRenderable.h"

class UIObject : public TransformableObject, public IRenderable
{
public:
    friend class GameInterface;
    ~UIObject() override;

protected:
    void onEnable() override;
    void onDisable() override;

    GameInterface* m_gameInterface;
private:
    Event<UIObject*, bool> m_activeChangedEvent;
    void addActiveChangedListener(const Action<UIObject*, bool>& onActiveChangedListener);
};
