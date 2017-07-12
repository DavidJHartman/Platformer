#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <Primitives/Vector2.hpp>
#include <Primitives/Rectangle.h>
#include <Primitives/Circle.hpp>
#include <Physics/CollisionDetection.hpp>
#include <UI/GUIStyle.hpp>

struct ButtonState {
    bool clickable = true;
    bool visible = true;
    bool clicked = false;
    bool moveable = false;
};

class UIObject {
private:
    void (*hover_function)(void** objectsInteractedWith, ButtonState* state);
    void (*clicked_function)(void** objectsInteractedWith, ButtonState* state);
    void (*released_function)(void** objectsInteractedWith, ButtonState* state);

    Vector2f Position;
    RectangleFloat BoundingBox;

    sf::RectangleShape rectangle;

    void** objectsInteractedWith;
    UIObject** childObjects;

    GUIStyle* style;

public:

    void interaction(sf::Vector2f mousePosition, bool clicked);

    void setStyle(GUIStyle* style) {this->style = style;}
    void setHoverFunction( void (*newHoverFunc)(void**, ButtonState*) ){ this->hover_function = newHoverFunc; }
    void setClickedFunction( void (*newClickedFunc)(void**, ButtonState*) ){ this->clicked_function = newClickedFunc; }
    void setReleasedFunction( void (*newReleasedFunc)(void**, ButtonState*) ){ this->released_function = newReleasedFunc; }

    UIObject(){}
    UIObject(Vector2f Position, Vector2f Dimensions);
};

class TextBox : UIObject {
private:
    std::string TextToDisplay;
    bool Wrapping;

public:
    void Draw( sf::RenderWindow& window );
};

class TexturedBox : UIObject {
private:
    sf::Texture* texture;
    sf::Sprite* sprite;

public:
    void Draw( sf::RenderWindow& window );

    TexturedBox( sf::Vector2f pos, std::string filename );
    TexturedBox( sf::Vector2f pos, sf::Sprite* sprite);
    TexturedBox( sf::Vector2f pos, sf::Texture* texture);
};


#endif // UI_HPP_INCLUDED
