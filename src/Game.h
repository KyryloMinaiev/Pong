#pragma once
#include <memory>

#include "DIContainer/Container.h"
#include "DIContainer/IUpdatable.h"

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
    std::unique_ptr<Container> m_container;
};
