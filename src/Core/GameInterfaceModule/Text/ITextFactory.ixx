export module ITextFactory;

import Text;
import TextSettings;
import <string>;

export class ITextFactory
{
public:
    virtual ~ITextFactory() = default;
    virtual Text* createText(const std::string& name = "Text", const TextSettings& settings = TextSettings()) = 0;
};
