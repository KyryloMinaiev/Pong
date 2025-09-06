export module IInitializable;

export class IInitializable
{
public:
    virtual ~IInitializable() = default;
    virtual void initialize() = 0;
};