#include "MainMenuModule.h"

MainMenuModule::MainMenuModule() = default;

void MainMenuModule::inject(Container* container, sf::RenderWindow* window)
{
    m_container = container;
}
