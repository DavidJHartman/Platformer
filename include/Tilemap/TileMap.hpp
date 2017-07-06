#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED
#include <string>

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


};


#endif // TILEMAP_HPP_INCLUDED
