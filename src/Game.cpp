#include "Game.h"
#include "DIContainer/Container.h"

Game::Game(sf::RenderWindow* window) : m_window(window), m_container(std::make_unique<Container>())
{ }

Game::~Game() = default;

void Game::update(float deltaTime)
{
}
