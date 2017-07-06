#ifndef TILESET_HPP_INCLUDED
#define TILESET_HPP_INCLUDED
#include <SFML/Graphics.hpp>

class TileSet {
    int firstGID;

    std::string source;
    std::string name;
    int tileWidth;
    int tileHeight;
    int spacing; // this is the padding between tiles
    int margin; // this is the space between tiles and the edge of the picture

    int tileCount;
    int columns;
};

#endif // TILESET_HPP_INCLUDED
