
#include <SFML\Graphics.hpp>

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(videoMode, "Pong", sf::State::Fullscreen);
    
    return 0;
}
