#include <UI/GUIWidgets.hpp>

void generateTextBox( UIObject& newObject, Vector2f Position, Vector2f Dimensions, std::string TextToDisplay, bool Wrapped ){

    if ( newObject.style == nullptr ) {
        std::cerr << "You must apply a style to a UIObject before generating a text box!" << std::endl;
        return;
    }

    newObject.setBoundingBox( Position, Dimensions );
    generateStyledRectangle( newObject );

    if ( Wrapped )
        newObject.Draw = RenderWrappedTextBox;
    else
        newObject.Draw = RenderUnwrappedTextBox;

    newObject.objectsInteractedWith = (void**)malloc( 1 * sizeof( void* ) );
    newObject.objectsInteractedWith[0] = new std::string( TextToDisplay );

}

void generateTileBox( UIObject& newObject, Vector2f Position, Vector2f Dimensions, std::vector<TileSet*> tileSets ) {

    if ( newObject.style == nullptr ) {
        std::cerr << "You must apply a style to a UIObject before generating a text box!" << std::endl;
        return;
    }

    newObject.setBoundingBox( Position, Dimensions );
    generateStyledRectangle( newObject );

    newObject.objectsInteractedWith = (void**)malloc( tileSets.size() * sizeof( void* ) );
    for ( int i = 0; i < tileSets.size(); i++ ) {
        TileSet* tempTileSet = tileSets[i];
    }

}

void RenderUnwrappedTextBox( sf::RenderWindow& window, UIObject& TextBox ) {
    std::cerr << "This function has not been designed yet Sorry \n";
}

void RenderWrappedTextBox( sf::RenderWindow& window, UIObject& TextBox ) {
    sf::RectangleShape& GUIRect = *(sf::RectangleShape*)(TextBox.Graphic);
    TextBox.style->applyStyle(&GUIRect);

    std::string TextToDisplay = *(std::string*)TextBox.objectsInteractedWith[0];

    window.draw(GUIRect);
    sf::Font font = (TextBox.style->font);

    std::string formattedText = "";
    std::string tempStr = "";
    int wordLength = 0, lineLength = 0;

    for ( int i = 0; i < TextToDisplay.size(); i++ ) {
        char _c = TextToDisplay[i];
        tempStr+=_c;
        wordLength+=font.getGlyph(_c,12,false).advance;
        if ( _c == ' ' || i == TextToDisplay.size()-1 ){
            lineLength+=wordLength;
            if (lineLength < TextBox.BoundingBox.HalfDimensions.x*2 - (TextBox.style->borderSize * 2)){
                formattedText+= tempStr;
                tempStr.clear();
                wordLength = 0;
            }
            else{
                formattedText+= '\n' + tempStr;
                lineLength = wordLength;
                wordLength = 0;
                tempStr.clear();
            }
        }
    }
    sf::Text text;
    text.setCharacterSize(12);
    text.setString( formattedText );
    text.setPosition(TextBox.BoundingBox.Position.x - TextBox.BoundingBox.HalfDimensions.x + TextBox.style->borderSize * 2, TextBox.BoundingBox.Position.y - TextBox.BoundingBox.HalfDimensions.y + TextBox.style->borderSize * 2);
    text.setFont( font );
    text.setFillColor( sf::Color::White);

    window.draw(text);
}

void generateStyledRectangle( UIObject& newObject ) {
    sf::RectangleShape* GUIRect = new sf::RectangleShape;
    GUIRect->setOrigin(newObject.BoundingBox.HalfDimensions.x, newObject.BoundingBox.HalfDimensions.y );
    GUIRect->setPosition( sf::Vector2f(newObject.BoundingBox.Position.x, newObject.BoundingBox.Position.y) );
    GUIRect->setSize( sf::Vector2f( newObject.BoundingBox.HalfDimensions.x * 2, newObject.BoundingBox.HalfDimensions.y * 2) );

    newObject.Graphic = (void*)GUIRect;
}
