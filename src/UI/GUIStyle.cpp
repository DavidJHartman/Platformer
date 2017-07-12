#include <UI/GUIStyle.hpp>

void GUIStyle::applyStyle(sf::Shape* shape) {
        shape->setFillColor(bodyCol);
        shape->setOutlineColor(borderCol);
        shape->setOutlineThickness(borderSize);
}

void GUIStyle::highlightShape(sf::Shape* shape) {
    shape->setFillColor(bodyHighlightCol);
    shape->setOutlineColor(borderHighlightCol);
}
