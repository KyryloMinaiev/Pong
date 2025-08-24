#pragma once

#include "../Core/ObjectsModule/TransformableObject.h"
#include "../RenderModule/IRenderable.h"

class UIObject : public TransformableObject, public IRenderable
{
public:
    ~UIObject() override;
};
