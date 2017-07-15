#include <UI/UI.hpp>

UIObject::UIObject(Vector2f Position, Vector2f Dimensions) {
    this->Position = Position;
    BoundingBox.Position = Position;
    BoundingBox.HalfDimensions = Vector2f(Dimensions.x / 2, Dimensions.y / 2);
    rectangle.setOrigin(Dimensions.x/2, Dimensions.y/2);
}

void UIObject::interaction( sf::Vector2i mousePosition, bool clicked ) {
    if ( axisAllignedBoundingBoxContains(Vector2f(mousePosition.x, mousePosition.y), BoundingBox)) {
        if ( hover_function != nullptr )hover_function(objectsInteractedWith, &State);
        if ( clicked && clicked_function != nullptr )
            clicked_function(objectsInteractedWith, &State);
    }
}

TexturedBox::TexturedBox( Vector2f Position, Vector2f Dimensions, std::string filename ) {
    this->texture->loadFromFile( filename );
}

TexturedBox::TexturedBox( Vector2f Position, Vector2f Dimensions, sf::Texture* texture ) : UIObject(Position, Dimensions){
    this->texture = texture;
    rectangle.setTexture((this->texture));
}

TexturedBox::TexturedBox( Vector2f Position, Vector2f Dimensions, int tileID ) : UIObject(Position, Dimensions){

}

TextBox::TextBox( Vector2f Position, Vector2f Dimensions, std::string TextToDisplay ) : UIObject( Position, Dimensions) {
    this->TextToDisplay = TextToDisplay;
}

void TextBox::Draw( sf::RenderWindow& window ) {

    style->applyStyle(&rectangle);
    rectangle.setPosition( sf::Vector2f(Position.x, Position.y) );
    rectangle.setSize( sf::Vector2f( BoundingBox.HalfDimensions.x * 2, BoundingBox.HalfDimensions.y * 2) );
    window.draw(rectangle);
    font = (style->font);

    std::string formattedText = "";
    std::string tempStr = "";
    int wordLength = 0, lineLength = 0;
    for ( int i = 0; i < TextToDisplay.size(); i++ ) {
        char _c = TextToDisplay[i];
        tempStr+=_c;
        wordLength+=font.getGlyph(_c,12,false).advance;
        if ( _c == ' ' || i == TextToDisplay.size()-2 ){
            lineLength+=wordLength;
            if (lineLength < BoundingBox.HalfDimensions.x*2 - (style->borderSize * 2)){
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
    text.setPosition(Position.x - BoundingBox.HalfDimensions.x + style->borderSize * 2, Position.y - BoundingBox.HalfDimensions.y + style->borderSize * 2);
    text.setFont( font );

    window.draw(text);
}
