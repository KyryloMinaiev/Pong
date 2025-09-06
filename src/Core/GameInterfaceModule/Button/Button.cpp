module Button;

void Button::update(float deltaTime)
{
    
}

void Button::executeOnClickListeners() const
{
    m_onClickListeners.invoke();
}

void Button::setup(const ButtonSettings& buttonSettings)
{
    m_buttonSettings = buttonSettings;
    setColor(m_buttonSettings.normalColor);
}

void Button::addOnClickListener(const Action<>& listener)
{
    m_onClickListeners.addListener(listener);
}

void Button::removeOnClickListener(const Action<>& listener)
{
    m_onClickListeners.removeListener(listener);
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
