#include "Game.h"

#include <SFML\Graphics.hpp>

#include "GlobalInstaller.h"
#include "GameInterfaceModule/GameInterface.h"
#include "GameInterfaceModule/Text/ITextFactory.h"


Game::Game(sf::RenderWindow* window) : m_window(window), m_container(std::make_unique<Container>())
{
    m_container->registerObject<sf::RenderWindow>(window);
    m_container->install<GlobalInstaller>();

    m_gameInterface = m_container->resolve<GameInterface>();
}

Game::~Game() = default;

void Game::update(float deltaTime)
{
    m_container->update(deltaTime);
    m_gameInterface->render();
}
