export module ApplicationState;

export class ApplicationState
{
public:
    virtual ~ApplicationState() = default;
    virtual void enterState() = 0;
    virtual void exitState() = 0;
};