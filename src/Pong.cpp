
#include <SFML\Graphics.hpp>

#include "Game.h"

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(videoMode, "Pong", sf::State::Fullscreen);
    std::unique_ptr<Game> game = std::make_unique<Game>(&window);
    sf::Clock clock;
    while (window.isOpen())
    {
        window.clear();
        float deltaTime = clock.restart().asSeconds();
        game->update(deltaTime);
    }
    
    return 0;
}
