#include <Tilemap/TileMap.hpp>

void TileMap::Render() {

    int xStart = tileMapWidth * !RenderOrder.RightOrLeft + ( -1 * !RenderOrder.RightOrLeft );
    int yStart = tileMapHeight * !RenderOrder.DownOrUp + ( -1 * !RenderOrder.DownOrUp );

    int xIterator = (1 + ( -2 * !RenderOrder.RightOrLeft ) );
    int yIterator = (1 + ( -2 * !RenderOrder.DownOrUp ) );

    int xCheck = ( tileMapWidth * RenderOrder.RightOrLeft ) - ( 1 * !RenderOrder.RightOrLeft );
    int yCheck = ( tileMapHeight * RenderOrder.DownOrUp ) - ( 1 * !RenderOrder.DownOrUp );

    for ( int x = xStart; x != xCheck; x += xIterator ) {
        for ( int y = yStart; y != yCheck; y += yIterator ) {
            // DRAW
        }
    }
}

bool TileMap::loadMap( std::string filename ) {

    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename.c_str());

}
