#include "SFML/SFMLImport.h"

export module IInputManager;

import Delegates;

export class IInputManager
{
public:
    virtual ~IInputManager() = default;
    virtual void addTextInputEventListener(const Action<char32_t>& listener) = 0;
    virtual void removeTextInputEventListener(const Action<char32_t>& listener) = 0;

    virtual void addKeyPressedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) = 0;
    virtual void removeKeyPressedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) = 0;

    virtual void addKeyReleasedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) = 0;
    virtual void removeKeyReleasedInputEventListener(sf::Keyboard::Key key, const Action<void>& listener) = 0;
};
