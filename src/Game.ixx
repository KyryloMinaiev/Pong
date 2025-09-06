#include "SFML/SFMLImport.h"

export module Game;

import ObjectsModule;
import DIContainer;
import GameInterfaceModule;
import <memory>;

export class Game
{
public:
    explicit Game(sf::RenderWindow* window);
    ~Game();
    
    void update(float deltaTime);

private:
    sf::RenderWindow* m_window;
    std::unique_ptr<ObjectsContainer> m_objectsContainer;
    std::unique_ptr<ObjectFactory> m_objectFactory;
    std::unique_ptr<Container> m_container;
    GameInterface* m_gameInterface;
};
