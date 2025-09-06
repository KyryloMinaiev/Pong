module TextSettings;



TextSettings::TextSettings(std::string text, unsigned int size,
                           const sf::Color& color, unsigned int style,
                           const sf::Color& outline, unsigned int outlineThickness):
    text(std::move(text)),
    size(size),
    color(color),
    style(style),
    outline(outline),
    outlineThickness(outlineThickness)
{
}
