#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <Primitives/Vector2.hpp>
#include <Primitives/Rectangle.h>
#include <Primitives/Circle.hpp>
#include <Physics/CollisionDetection.hpp>

struct ButtonState {
    bool clickable = true;
    bool visible = true;
};

class UIObject {
//private:
public:
    void (*hover_function)(void** objectsInteractedWith, ButtonState* state);
    void (*clicked_function)(void** objectsInteractedWith, ButtonState* state);
    void (*released_function)(void** objectsInteractedWith, ButtonState* state);

    Vector2f Position;
    RectangleFloat BoundingBox;

    sf::RectangleShape rectangle;

    void** objectsInteractedWith;
    UIObject** childObjects;

public:

    void interaction(sf::Vector2f mousePosition, bool clicked);

    void setHoverFunction( void* hover_function );

    UIObject(){}
    UIObject(Vector2f Position, Vector2f Dimensions);
};
#endif // UI_HPP_INCLUDED
