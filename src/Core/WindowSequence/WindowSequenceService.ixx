#include "SFML/SFMLImport.h"

export module WindowSequenceService;

import DIContainer;
import WindowEventHandler;
import Delegates;

export class WindowSequenceService : public IInitializable
{
public:
    WindowSequenceService();
    ~WindowSequenceService() override;
    void inject(sf::RenderWindow* window, WindowEventHandler* windowEventHandler);
    void initialize() override;

private:
    void onWindowClosedEvent(const sf::Event::Closed* closedEvent);
    
    sf::RenderWindow* m_window;
    WindowEventHandler* m_windowEventHandler;

    Action<const sf::Event::Closed*> m_windowClosedAction;
};
