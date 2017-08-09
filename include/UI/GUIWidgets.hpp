#ifndef GUIWIDGETS_HPP_INCLUDED
#define GUIWIDGETS_HPP_INCLUDED
#include <UI/UI.hpp>

void RenderWrappedTextBox( sf::RenderWindow& window, UIObject& TextBox );
void RenderUnwrappedTextBox( sf::RenderWindow& window, UIObject& TextBox );

void generateTextBox( UIObject& newObject, Vector2f Position, Vector2f Dimensions, std::string TextToDisplay, bool Wrapped );
void generateTileBox( UIObject& newObject, Vector2f Position, Vector2f Dimensions, std::vector<TileSet*> tileSets );

void generateStyledRectangle ( UIObject& newObject );
#endif // GUIWIDGETS_HPP_INCLUDED
