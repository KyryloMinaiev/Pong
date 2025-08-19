#pragma once

#include <iostream>
#include <ostream>

class Container;

class MainMenuModule
{
public:
    MainMenuModule();
    void inject(Container* container);

    void Test()
    {
        std::cout << "Test" << std::endl;
    }

private:
    Container* m_container;
};
