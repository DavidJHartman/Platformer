#include <UI/GUIWidgets.hpp>

/*

    THE STANDARD GUI FUNCTION GOES LIKE THIS:

    void generateNameOfObject( UIObject& newObject, Vector2f Position, Vector2f Dimensions, data relevant to button, relevant info ) {

        ERROR CATCHING

        DEFINE newObject

        DEFINE STATE OF OBJECT

        FILL IN objectsInteractedWith

    }


*/

void generateTextBox( UIObject& newObject, Vector2f Position, Vector2f Dimensions, std::string TextToDisplay, bool Wrapped ){

    // ERROR CATCHING TO SEE IF YOU HAVE SET A STYLE FOR THE UIOBJECT
    /*
        This is important because it is used to define the actual object itself,
        as in the colors, size of the border, transparency and everything. It is
        important to use styles to have a consistent look everywhere.
    */
    if ( newObject.style == nullptr ) {
        std::cerr << "You must apply a style to a UIObject before generating a text box!" << std::endl;
        return;
    }

    /*
        Unless your UIObject will never be interacted with, these functions will always be used, the first
        to set up collision detection as well as where it exists in space, the second to apply the style to
        the graphic. Remember, we use a lot of C rather than C++ here because of so many pointers being thrown
        around. It's very low level stuff.
    */
    newObject.setBoundingBox( Position, Dimensions );
    generateStyledRectangle( newObject );

    // These are specific to the textbox itself
    if ( Wrapped )
        newObject.Draw = RenderWrappedTextBox;
    else
        newObject.Draw = RenderUnwrappedTextBox;

    /*
        This is where shit gets weird. The buttons have a void** that keep a list of pointers to things they
        interact with. This lets us do cool shit like have a UIObject that shits out a framerate as a graph
        if we want or have thumbnails of our sprites or whatever we want. A void* is a pointer to anything or
            nothing. So what we do is
            1. Cast the malloc as a (void**) // an array of void*
            2. call malloc // the c function for allocating dynamic memory
            3. the arguments for malloc are always ( amount * sizeof( object ) )
        in all, the line we use first says " I want a pointer to a block of memory the size of one pointer that is of type void** "
    */
    newObject.objectsInteractedWith = (void**)malloc( 1 * sizeof( void* ) );

    // We then can do this
    newObject.objectsInteractedWith[0] = new std::string( TextToDisplay );

    /* But we could also do this:
        newObject.objectsInteractedWith[0] = (void*)malloc( sizeof(void*) );
        (*newObject.objectsInteractedWith[0]) = std::string( TextToDisplay );

        but instead I used a bit of C++ (the new keyword) to skip some shit.
    */

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
        newObject.objectsInteractedWith[i] = (void*)malloc( sizeof( void* ) );
        newObject.objectsInteractedWith[i] = tileSets[i];
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
