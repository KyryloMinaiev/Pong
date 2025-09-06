export module Button;

import ButtonSettings;
import Image;
import DIContainer;
import Delegates;
import IFocusable;
import IInteractable;

export class Button : public Image, public IInteractable, public IFocusable, public IUpdatable
{
public:
    ~Button() override = default;
    
    void setup(const ButtonSettings& buttonSettings);
    
    void addOnClickListener(const Action<>& listener);
    void removeOnClickListener(const Action<>& listener);

    void beginInteraction() override;
    void endInteraction() override;

    void focus() override;
    void unfocus() override;

    void update(float deltaTime) override;
private:
    void executeOnClickListeners() const;
    
    Event<> m_onClickListeners;
    ButtonSettings m_buttonSettings;
};
