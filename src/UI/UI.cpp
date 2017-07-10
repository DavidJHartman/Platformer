#include <UI/UI.hpp>

UIObject::UIObject(Vector2f Position, Vector2f Dimensions) {
    this->Position = Position;
    BoundingBox.Position = Position;
    BoundingBox.HalfDimensions = Vector2f(Dimensions.x / 2, Dimensions.y / 2);
}

void UIObject::interaction( sf::Vector2f mousePosition, bool clicked ) {
    if ( axisAllignedBoundingBoxContains(Vector2f(mousePosition.x, mousePosition.y), BoundingBox)) {
        hover_function(nullptr, nullptr);
    }
}
