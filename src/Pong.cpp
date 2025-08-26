
#include <SFML\Graphics.hpp>

#include "Game.h"

int WinMain()
{
    sf::VideoMode videoMode = sf::VideoMode(sf::Vector2u(1080, 720));
    sf::RenderWindow window(videoMode, "Pong", sf::Style::Titlebar | sf::Style::Close, sf::State::Windowed);
    window.setFramerateLimit(60);
    std::unique_ptr<Game> game = std::make_unique<Game>(&window);
    sf::Clock clock;
    while (window.isOpen())
    {
        window.clear();
        float deltaTime = clock.restart().asSeconds();
        game->update(deltaTime);
        window.display();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
    }
    
    return 0;
}
