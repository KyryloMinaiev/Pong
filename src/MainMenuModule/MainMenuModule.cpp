#include "MainMenuModule.h"

MainMenuModule::MainMenuModule() = default;

void MainMenuModule::inject(Container* container)
{
    m_container = container;
}
