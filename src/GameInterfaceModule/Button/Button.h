#pragma once

#include "ButtonSettings.h"
#include "../IFocusable.h"
#include "../IInteractable.h"
#include "../../Core/Delegates/Event.h"
#include "../../Core/DIContainer/IUpdatable.h"
#include "../Image/Image.h"

class Button : public Image, public IInteractable, public IFocusable, public IUpdatable
{
public:
    ~Button() override = default;
    
    void setup(const ButtonSettings& buttonSettings);
    
    void addOnClickListener(const Action<>& listener);
    void removeOnClickListener(const Action<>& listener);

    void beginInteraction() override;
    void endInteraction() override;

    void focus() override;
    void unfocus() override;

    void update(float deltaTime) override;
private:
    void executeOnClickListeners() const;
    
    Event<> m_onClickListeners;
    ButtonSettings m_buttonSettings;
};
