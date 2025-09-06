module InputManager;

InputManager::InputManager()
{
    m_keyPressedListener = CreateAction(this, &InputManager::onKeyPressedEvent);
    m_keyReleasedListener = CreateAction(this, &InputManager::onKeyReleasedEvent);
    m_textEnteredListener = CreateAction(this, &InputManager::onTextEnteredEvent);  
}

InputManager::~InputManager()
{
    m_windowEventHandler->removeEventListener(m_keyPressedListener);
    m_windowEventHandler->removeEventListener(m_keyReleasedListener);
    m_windowEventHandler->removeEventListener(m_textEnteredListener);
}

void InputManager::initialize()
{
    m_windowEventHandler->addEventListener(m_keyPressedListener);
    m_windowEventHandler->addEventListener(m_keyReleasedListener);
    m_windowEventHandler->addEventListener(m_textEnteredListener);
}

void InputManager::inject(WindowEventHandler* windowEventHandler)
{
    m_windowEventHandler = windowEventHandler;
}

void InputManager::addTextInputEventListener(const Action<char32_t>& listener)
{
    m_textListeners.addListener(listener);
}

void InputManager::removeTextInputEventListener(const Action<char32_t>& listener)
{
    m_textListeners.removeListener(listener);
}

void InputManager::addKeyPressedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener)
{
    if (!m_keyPressedListeners.contains(key))
    {
        m_keyPressedListeners.insert({key, Event()});
    }

    m_keyPressedListeners[key].addListener(listener);
}

void InputManager::removeKeyPressedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener)
{
    if (m_keyPressedListeners.contains(key))
    {
        m_keyPressedListeners[key].removeListener(listener);
    }
}

void InputManager::addKeyReleasedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener)
{
    if (!m_keyReleasedListeners.contains(key))
    {
        m_keyReleasedListeners.insert({key, Event()});
    }

    m_keyReleasedListeners[key].addListener(listener);
}

void InputManager::removeKeyReleasedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener)
{
    if (m_keyReleasedListeners.contains(key))
    {
        m_keyReleasedListeners[key].removeListener(listener);
    }
}

void InputManager::onTextEnteredEvent(const sf::Event::TextEntered* textEnteredEvent)
{
    auto text = textEnteredEvent->unicode;
    m_textListeners.invoke(text); 
}

void InputManager::onKeyPressedEvent(const sf::Event::KeyPressed* keyPressedEvent)
{
    auto key = keyPressedEvent->code;
    if (m_keyPressedListeners.contains(key))
    {
        m_keyPressedListeners[key].invoke();
    }
}

void InputManager::onKeyReleasedEvent(const sf::Event::KeyReleased* keyReleasedEvent)
{
    auto key = keyReleasedEvent->code;
    if (m_keyReleasedListeners.contains(key))
    {
        m_keyReleasedListeners[key].invoke();
    }
}
