#include <Tilemap/TileMap.hpp>

void TileMap::Render(sf::RenderWindow& window) {
    for ( int i = 0; i < layers.size(); i++ ) {
        for ( int x = RenderOrder.RightOrLeft ? tileMapWidth - 1 : 0; x != (RenderOrder.RightOrLeft ? 0 : tileMapWidth - 1); x += (RenderOrder.RightOrLeft ? -1 : 1) ) {
            for ( int y = RenderOrder.DownOrUp ? tileMapHeight - 1 : 0; y != (RenderOrder.DownOrUp ? 0 : tileMapHeight - 1); y += (RenderOrder.DownOrUp ? -1 : 1 )) {
                tilesets[0].Draw(window, layers[i].Tiles[y * layers[i].height + x], x * 16, y * 16);
            }
        }
    }
}

bool TileMap::loadMap( std::string filename ) {

    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename.c_str());

    tinyxml2::XMLElement* MapElement = doc.FirstChildElement( "map" );

    VersionNumber = atoi(MapElement->FindAttribute("version")->Value());
    TiledVersion = atoi(MapElement->FindAttribute("tiledversion")->Value());

    std::string orientation = MapElement->FindAttribute("orientation")->Value();
    if (orientation == "orthogonal")
        Orientation = orthogonal;
    else if (orientation == "isometric")
        Orientation = isometric;
    else if (orientation == "staggered")
        Orientation = staggered;
    else if (orientation == "hexagonal")
        Orientation = hexagonal;

    tileMapWidth = atoi(MapElement->FindAttribute("width")->Value());
    tileMapHeight = atoi(MapElement->FindAttribute("height")->Value());

    tileWidth = atoi(MapElement->FindAttribute("tilewidth")->Value());
    tileHeight = atoi(MapElement->FindAttribute("tileheight")->Value());

    nextObjectID = atoi(MapElement->FindAttribute("nextobjectid")->Value());

    tinyxml2::XMLElement* tilesetElement = MapElement->FirstChildElement( "tileset" );

    tilesets.push_back(TileSet());
    tilesets[tilesets.size()-1].LoadTileset(tilesetElement->FindAttribute("source")->Value());
    tinyxml2::XMLElement* layerElement = MapElement->FirstChildElement( "layer" );
    layers.push_back(Layer());
    layers[0].name = layerElement->FindAttribute( "name" )->Value();
    layers[0].width = atoi(layerElement->FindAttribute( "width" )->Value());
    layers[0].height = atoi(layerElement->FindAttribute( "height" )->Value());
    tinyxml2::XMLElement* layerData = layerElement->FirstChildElement("data");
    std::string data = layerData->GetText();

    for (int i = 0; i < data.size(); i++ ) {
        if (data[i] == ',' || data[i] == '\n')continue;
        layers[0].Tiles.push_back(data[i]-'0'-1);
    }
}
