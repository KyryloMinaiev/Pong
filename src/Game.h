#pragma once
#include "Interfaces/IUpdatable.h"

namespace sf
{
    class RenderWindow;
}

class Game : public IUpdatable
{
public:
    explicit Game(sf::RenderWindow* window);
    ~Game() override;
    
    void update(float deltaTime) override;

private:
    sf::RenderWindow* m_window;
};
