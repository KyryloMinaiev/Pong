#pragma once

#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderWindow.hpp>

class Container;

class MainMenuModule
{
public:
    MainMenuModule();
    virtual ~MainMenuModule() = default;
    void inject(Container* container, sf::RenderWindow* window);
private:
    Container* m_container;
};
