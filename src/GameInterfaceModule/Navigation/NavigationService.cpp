#include "NavigationService.h"

#include "../IInteractable.h"
#include "../IFocusable.h"
#include "../UIObject.h"

NavigationService::NavigationService() : m_navigationTree(std::make_unique<NavigationTree>())
{
    m_onSubmitKeyPressedAction = CreateAction(this, &NavigationService::onSubmitKeyPressed);
    m_onSubmitKeyReleasedAction = CreateAction(this, &NavigationService::onSubmitKeyReleased);

    m_onUpButtonPressedAction = CreateAction(this, &NavigationService::onUpButtonPressed);
    m_onDownButtonPressedAction = CreateAction(this, &NavigationService::onDownButtonPressed);
    m_onLeftButtonPressedAction = CreateAction(this, &NavigationService::onLeftButtonPressed);
    m_onRightButtonPressedAction = CreateAction(this, &NavigationService::onRightButtonPressed);

    m_onFocusedObjectChangedAction = CreateAction(this, &NavigationService::onFocusedObjectChanged);
    m_navigationTree->onNavigationElementChanged.addListener(m_onFocusedObjectChangedAction);
}

NavigationService::~NavigationService()
{
    m_inputManager->removeKeyPressedInputEventListener(sf::Keyboard::Key::Enter, m_onSubmitKeyPressedAction);
    m_inputManager->removeKeyReleasedInputEventListener(sf::Keyboard::Key::Enter, m_onSubmitKeyReleasedAction);

    m_inputManager->removeKeyPressedInputEventListener(sf::Keyboard::Key::Up, m_onUpButtonPressedAction);
    m_inputManager->removeKeyPressedInputEventListener(sf::Keyboard::Key::Down, m_onDownButtonPressedAction);
    m_inputManager->removeKeyPressedInputEventListener(sf::Keyboard::Key::Left, m_onLeftButtonPressedAction);
    m_inputManager->removeKeyPressedInputEventListener(sf::Keyboard::Key::Right, m_onRightButtonPressedAction);
}

void NavigationService::inject(IInputManager* inputManager)
{
    m_inputManager = inputManager;
}

void NavigationService::initialize()
{
    m_inputManager->addKeyPressedInputEventListener(sf::Keyboard::Key::Enter, m_onSubmitKeyPressedAction);
    m_inputManager->addKeyReleasedInputEventListener(sf::Keyboard::Key::Enter, m_onSubmitKeyReleasedAction);

    m_inputManager->addKeyPressedInputEventListener(sf::Keyboard::Key::Up, m_onUpButtonPressedAction);
    m_inputManager->addKeyPressedInputEventListener(sf::Keyboard::Key::Down, m_onDownButtonPressedAction);
    m_inputManager->addKeyPressedInputEventListener(sf::Keyboard::Key::Left, m_onLeftButtonPressedAction);
    m_inputManager->addKeyPressedInputEventListener(sf::Keyboard::Key::Right, m_onRightButtonPressedAction);
}

void NavigationService::update(float deltaTime)
{
    m_navigationTree->update();
}

void NavigationService::onSubmitKeyPressed()
{
    if (IInteractable* interactable = m_focusedObject->getInteractable())
    {
        interactable->beginInteraction();
    }
}

void NavigationService::onSubmitKeyReleased()
{
    if (IInteractable* interactable = m_focusedObject->getInteractable())
    {
        interactable->endInteraction();
    }
}

void NavigationService::onUpButtonPressed()
{
    m_navigationTree->moveNavigation(NavigationDirection::UP);
}

void NavigationService::onDownButtonPressed()
{
    m_navigationTree->moveNavigation(NavigationDirection::DOWN);
}

void NavigationService::onLeftButtonPressed()
{
    m_navigationTree->moveNavigation(NavigationDirection::LEFT);
}

void NavigationService::onRightButtonPressed()
{
    m_navigationTree->moveNavigation(NavigationDirection::RIGHT);
}

void NavigationService::onFocusedObjectChanged(NavigationElement* focusedObject)
{
    m_focusedObject = focusedObject;
    if (m_focusedObject)
    {
        m_focusedObject->getFocusable()->focus();
    }
}

void NavigationService::insertUIObject(UIObject* uiObject) const
{
    if (!uiObject)
    {
        return;
    }

    m_navigationTree->addNavigationElement(uiObject);
}

void NavigationService::removeUIObject(UIObject* uiObject) const
{
    if (!uiObject)
    {
        return;
    }

    m_navigationTree->removeNavigationElement(uiObject);   
}
