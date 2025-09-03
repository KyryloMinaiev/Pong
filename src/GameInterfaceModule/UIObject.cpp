#include "UIObject.h"

#include "GameInterface.h"

UIObject::~UIObject() = default;

void UIObject::onEnable()
{
    TransformableObject::onEnable();
    m_activeChangedEvent.invoke(this, true);
}

void UIObject::onDisable()
{
    TransformableObject::onDisable();
    m_activeChangedEvent.invoke(this, false);
}

void UIObject::addActiveChangedListener(const Action<UIObject*, bool>& onActiveChangedListener)
{
    m_activeChangedEvent.addListener(onActiveChangedListener);
}
