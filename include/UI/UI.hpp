#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <Primitives/Vector2.hpp>
#include <Primitives/Rectangle.h>
#include <Primitives/Circle.hpp>
#include <Physics/CollisionDetection.hpp>
#include <UI/GUIStyle.hpp>
#include <vector>

struct ButtonState {
    bool clickable = true;
    bool visible = true;
    bool clicked = false;
    bool moveable = false;
};

class UIObject {
protected:
    void (*hover_function)(void** objectsInteractedWith, ButtonState* state) = nullptr;
    void (*clicked_function)(void** objectsInteractedWith, ButtonState* state) = nullptr;
    void (*released_function)(void** objectsInteractedWith, ButtonState* state) = nullptr;

    Vector2f Position;
    RectangleFloat BoundingBox;


    void** objectsInteractedWith;
    ButtonState State;
    UIObject** childObjects;
    std::string title;

    GUIStyle* style;

public:
    sf::RectangleShape rectangle;

    void interaction(sf::Vector2i mousePosition, bool clicked);
    void setPosition( float x, float y ) { Position = Vector2f( x, y ); }
    void setSize( float x, float y ) { BoundingBox.HalfDimensions = Vector2f( x/2, y/2 ); }

    void setHoverFunction( void (*newHoverFunc)(void**, ButtonState*) ){ this->hover_function = newHoverFunc; }
    void setClickedFunction( void (*newClickedFunc)(void**, ButtonState*) ){ this->clicked_function = newClickedFunc; }
    void setReleasedFunction( void (*newReleasedFunc)(void**, ButtonState*) ){ this->released_function = newReleasedFunc; }

    void setStyle( GUIStyle* style ) { this->style = style; }

    UIObject(){}
    UIObject(Vector2f Position, Vector2f Dimensions);

    sf::Shape* getShape() { return &rectangle; }

    virtual void Draw( sf::RenderWindow& window ) {
        style->applyStyle(&rectangle);
        rectangle.setPosition( sf::Vector2f(Position.x, Position.y) );
        rectangle.setSize( sf::Vector2f( BoundingBox.HalfDimensions.x * 2, BoundingBox.HalfDimensions.y * 2) );
        window.draw(rectangle);
    }
};

class TextBox : public UIObject {
private:
    std::string TextToDisplay;
    sf::Font font;
    bool Wrapping;

public:
    TextBox( Vector2f Position, Vector2f Dimensions, std::string TextToDisplay );
    void Draw( sf::RenderWindow& window );
};

class TexturedBox : public UIObject {
public:
    sf::Texture* texture;

    TexturedBox( Vector2f Position, Vector2f Dimensions, std::string filename );
    TexturedBox( Vector2f Position, Vector2f Dimensions, sf::Texture* texture);
    TexturedBox( Vector2f Position, Vector2f Dimensions, int tileID );
    TexturedBox( ){ }
};

#endif // UI_HPP_INCLUDED
