module FontsProvider;

FontsProvider::~FontsProvider() = default;

void FontsProvider::initialize()
{
    m_defaultFont = std::make_unique<sf::Font>("res/fonts/DS-DIGIT.TTF");
}

sf::Font* FontsProvider::getDefaultFont()
{
    return m_defaultFont.get();  
}
