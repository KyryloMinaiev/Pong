#pragma once

namespace sf
{
    class RenderWindow;
}

class Game
{
public:
    explicit Game(sf::RenderWindow* window);
    ~Game();
    
    void update(float deltaTime);

private:
    sf::RenderWindow* m_window;
};
