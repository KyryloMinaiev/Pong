#include "Button.h"

#include <algorithm>

void Button::update(float deltaTime)
{
    
}

void Button::executeOnClickListeners() const
{
    for (auto& listener : m_onClickListeners)
    {
        listener();
    }  
}

void Button::setup(const ButtonSettings& buttonSettings)
{
    m_buttonSettings = buttonSettings;
    setColor(m_buttonSettings.normalColor);
}

void Button::addOnClickListener(const Action<>& listener)
{
    m_onClickListeners.push_back(listener);
}

void Button::removeOnClickListener(const Action<>& listener)
{
    auto it = std::find(m_onClickListeners.begin(), m_onClickListeners.end(), listener);
    if (it != m_onClickListeners.end()) {
        m_onClickListeners.erase(it);
    }
}

void Button::beginInteraction()
{
    setColor(m_buttonSettings.pressedColor);
}

void Button::endInteraction()
{
    setColor(m_buttonSettings.focusedColor);
    executeOnClickListeners();
}

void Button::focus()
{
    setColor(m_buttonSettings.focusedColor);
}

void Button::unfocus()
{
    setColor(m_buttonSettings.normalColor);
}
