#ifndef GUISTYLE_HPP_INCLUDED
#define GUISTYLE_HPP_INCLUDED
#include <SFML/Graphics.hpp>

class GUIStyle {
public:

    sf::Color bodyCol;
    sf::Color bodyHighlightCol;
    sf::Color borderCol;
    sf::Color borderHighlightCol;
    sf::Color textCol;
    sf::Color textHighlightCol;
    sf::Font* font;

    float borderSize;

    GuiStyle(sf::Font* font, float borderSize,
        sf::Color bodyCol, sf::Color borderCol, sf::Color textCol,
        sf::Color bodyHighlightCol, sf::Color borderHighlightCol, sf::Color textHighlightCol)
    {
        this->bodyCol = bodyCol;
        this->borderCol = borderCol;
        this->textCol = textCol;
        this->bodyHighlightCol = bodyHighlightCol;
        this->borderHighlightCol = borderHighlightCol;
        this->textHighlightCol = textHighlightCol;
        this->font = font;
        this->borderSize = borderSize;
    }
    GuiStyle() { }

    void applyStyle(sf::Shape* shape);
    void highlightShape(sf::Shape* shape);
};

#endif // GUISTYLE_HPP_INCLUDED
