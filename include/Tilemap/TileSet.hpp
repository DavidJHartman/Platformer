#ifndef TILESET_HPP_INCLUDED
#define TILESET_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <XML/tinyxml2.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <UI/UI.hpp>

class TileSet {
public:
    sf::Texture texture;
    sf::Sprite sprite;

//public:

    int firstGID;

    std::string source;
    std::string name;
    int tileWidth;
    int tileHeight;
    int spacing; // this is the padding between tiles
    int margin; // this is the space between tiles and the edge of the picture

    int tileCount;
    int columns;

    bool LoadTileset( std::string filename );
    void Draw( sf::RenderWindow& window, int id, int x, int y );
    void applyTileToTexturedUIObject( TexturedBox* box, int id );
};

#endif // TILESET_HPP_INCLUDED
