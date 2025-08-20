#include "Game.h"

#include <SFML\Graphics.hpp>
#include "MainMenuModule/MainMenuModule.h"

Game::Game(sf::RenderWindow* window) : m_window(window), m_container(std::make_unique<Container>())
{
    m_container->registerObject<sf::RenderWindow>(window);
}

Game::~Game() = default;

void Game::update(float deltaTime)
{
    m_container->update(deltaTime);
}
