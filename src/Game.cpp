module Game;

import GlobalInstaller;

Game::Game(sf::RenderWindow* window) : m_window(window), m_objectsContainer(std::make_unique<ObjectsContainer>()),
                                       m_objectFactory(std::make_unique<ObjectFactory>(m_objectsContainer.get())), 
                                       m_container(std::make_unique<Container>())
{
    m_container->registerObject<sf::RenderWindow>(window);
	m_container->registerObject<ObjectsContainer>(m_objectsContainer.get());
	m_container->registerObject<ObjectFactory>(m_objectFactory.get());
	m_container->setupObjectsFactory(m_objectFactory.get());
    m_container->install<GlobalInstaller>();

    m_gameInterface = m_container->resolve<GameInterface>();
}

Game::~Game() = default;

void Game::update(float deltaTime)
{
	m_objectsContainer->update(deltaTime);
    m_container->update(deltaTime);
    m_gameInterface->render();
}
