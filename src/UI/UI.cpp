#include <UI/UI.hpp>



UIObject::UIObject(Vector2f Position, Vector2f Dimensions) {
    this->BoundingBox.Position = Position;
    BoundingBox.HalfDimensions = Vector2f(Dimensions.x / 2, Dimensions.y / 2);
}

void UIObject::interaction( sf::Vector2i mousePosition, bool clicked ) {
    if ( axisAllignedBoundingBoxContains(Vector2f(mousePosition.x, mousePosition.y), BoundingBox)) {
        if ( hover_function != nullptr )hover_function(objectsInteractedWith, &State);
        if ( clicked && clicked_function != nullptr && State.clickable )
            clicked_function(objectsInteractedWith, &State);
    }
}

void DefaultDraw( sf::RenderWindow& window, UIObject& Widget ) {
    if ( Widget.State.visible == true ) {
        std::cerr << "You must apply a widget to this UIObject before rendering it!" << std::endl;
        Widget.State.visible = false;
    }

    return;
}
