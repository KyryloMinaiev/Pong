module;
#include "SFML/SFMLImport.h"

export module ButtonSettings;

export struct ButtonSettings
{
    sf::Color normalColor;
    sf::Color focusedColor;
    sf::Color pressedColor;
    float interactionTime;
    float focusedTime;

    ButtonSettings(const sf::Color& normalColor = {255, 255, 255, 255},
                   const sf::Color& focusedColor = {190, 190, 190, 255},
                   const sf::Color& pressedColor = {100, 100, 100, 255},
                   float interactionTime = 0.5f,
                   float focusedTime = 0.5f)
        : normalColor(normalColor),
          focusedColor(focusedColor),
          pressedColor(pressedColor),
          interactionTime(interactionTime),
          focusedTime(focusedTime)
    {
    }
};
