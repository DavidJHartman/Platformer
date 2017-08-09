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

class UIObject;

void DefaultDraw( sf::RenderWindow& window, UIObject& Widget );

class UIObject {
public:
    void (*hover_function)(void** objectsInteractedWith, ButtonState* state) = nullptr;
    void (*clicked_function)(void** objectsInteractedWith, ButtonState* state) = nullptr;
    void (*released_function)(void** objectsInteractedWith, ButtonState* state) = nullptr;

    RectangleFloat BoundingBox;


    void** objectsInteractedWith;
    ButtonState State;
    std::vector<UIObject> childObjects;
    std::string title;

    void* Graphic = nullptr;

    GUIStyle* style = nullptr;

    void interaction(sf::Vector2i mousePosition, bool clicked);
    void setPosition( float x, float y ) { BoundingBox.Position = Vector2f( x, y ); }
    void setSize( float x, float y ) { BoundingBox.HalfDimensions = Vector2f( x/2, y/2 ); }

    void setHoverFunction( void (*newHoverFunc)(void**, ButtonState*) ){ this->hover_function = newHoverFunc; }
    void setClickedFunction( void (*newClickedFunc)(void**, ButtonState*) ){ this->clicked_function = newClickedFunc; }
    void setReleasedFunction( void (*newReleasedFunc)(void**, ButtonState*) ){ this->released_function = newReleasedFunc; }

    void setStyle( GUIStyle* style ) { this->style = style; }
    void setGraphic( void* Graphic ) { this->Graphic = Graphic; }

    UIObject(){}
    UIObject(Vector2f Position, Vector2f Dimensions);

    void (*Draw)( sf::RenderWindow& window, UIObject& Widget ) = DefaultDraw;
};

#endif // UI_HPP_INCLUDED
