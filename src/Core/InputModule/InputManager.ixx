#include "SFML/SFMLImport.h"

export module InputManager;

import Delegates;
import IInputManager;
import DIContainer;
import WindowEventHandler;
import <unordered_map>;

export class InputManager : public IInputManager, public IInitializable
{
public:
    InputManager();
    ~InputManager() override;
    void initialize() override;
    void inject(WindowEventHandler* windowEventHandler);
    void addTextInputEventListener(const Action<char32_t>& listener) override;
    void removeTextInputEventListener(const Action<char32_t>& listener) override;
    void addKeyPressedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) override;
    void removeKeyPressedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) override;
    void addKeyReleasedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) override;
    void removeKeyReleasedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) override;
private:
    void onTextEnteredEvent(const sf::Event::TextEntered* textEnteredEvent);
    void onKeyPressedEvent(const sf::Event::KeyPressed* keyPressedEvent);
    void onKeyReleasedEvent(const sf::Event::KeyReleased* keyReleasedEvent);
    
    WindowEventHandler* m_windowEventHandler;
    Action<const sf::Event::TextEntered*> m_textEnteredListener;
    Action<const sf::Event::KeyPressed*> m_keyPressedListener;
    Action<const sf::Event::KeyReleased*> m_keyReleasedListener;
    
    std::unordered_map<sf::Keyboard::Key, Event<>> m_keyPressedListeners;
    std::unordered_map<sf::Keyboard::Key, Event<>> m_keyReleasedListeners;
    Event<char32_t> m_textListeners;
};
