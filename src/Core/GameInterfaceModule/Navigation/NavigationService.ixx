export module NavigationService;

import <memory>;

import InputManagement;
import UIObject;
import NavigationTree;
import DIContainer;
import NavigationElement;
import Delegates;

export class NavigationService : public IInitializable, public IUpdatable
{
public:
    NavigationService();
    ~NavigationService() override;

    void inject(IInputManager* inputManager);
    void initialize() override;
    void update(float deltaTime) override;
    
    void insertUIObject(UIObject* uiObject) const;
    void removeUIObject(UIObject* uiObject) const;
private:
    void onSubmitKeyPressed();
    void onSubmitKeyReleased();

    Action<> m_onSubmitKeyPressedAction;
    Action<> m_onSubmitKeyReleasedAction;

    void onUpButtonPressed();
    void onDownButtonPressed();
    void onLeftButtonPressed();
    void onRightButtonPressed();
    
    Action<> m_onUpButtonPressedAction;
    Action<> m_onDownButtonPressedAction;
    Action<> m_onLeftButtonPressedAction;
    Action<> m_onRightButtonPressedAction;

    void onFocusedObjectChanged(NavigationElement* focusedObject);
    Action<NavigationElement*> m_onFocusedObjectChangedAction;
    
    NavigationElement* m_focusedObject;
    std::unique_ptr<NavigationTree> m_navigationTree;
    IInputManager* m_inputManager;
};
