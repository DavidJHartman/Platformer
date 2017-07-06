#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED
#include <string>
#include <Tilemap/Layer.hpp>
#include <Tilemap/TileSet.hpp>
#include <XML/tinyxml2.h>

enum TileMapOrientation {
    orthogonal,
    isometric,
    staggered,
    hexagonal
};

enum TileMapStaggerAxis {
    X = true,
    Y = false
};

// On hexagonal or staggered maps,
enum TileMapStaggerIndex {
    Even = true,
    Odd = false
};

struct TileMapRenderOrder {
    bool RightOrLeft;
    bool DownOrUp;
};

class TileMap {

    Layer* layers;
    TileSet* tilesets;

    std::string VersionNumber;
    std::string TiledVersion;

    TileMapOrientation Orientation;
    TileMapRenderOrder RenderOrder;

    int tileMapWidth;
    int tileMapHeight;

    int tileWidth;
    int tileHeight;

    int hexSideLength;

    TileMapStaggerAxis StaggerAxis;

    int backgroundColor = 0x00000000;

    int nextObjectID;

public:
    void Render();

    bool loadMap(std::string filename);


};


#endif // TILEMAP_HPP_INCLUDED
