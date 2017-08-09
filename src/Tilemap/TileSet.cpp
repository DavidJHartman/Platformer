#include <Tilemap/TileSet.hpp>

void TileSet::Draw( sf::RenderWindow& window, int id, int x, int y ) {
    //if (id == -1)return;
    sprite.setPosition(x,y);
    sprite.setTextureRect(sf::IntRect(id * tileWidth, 0, tileWidth, tileHeight));
    window.draw(sprite);
}

bool TileSet::LoadTileset( std::string filename ) {

    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename.c_str());

    tinyxml2::XMLElement* titleElement = doc.FirstChildElement( "tileset" );
    tinyxml2::XMLElement* imageElement = titleElement->FirstChildElement( "image" );

    const tinyxml2::XMLAttribute* tileSetNameAttribute = titleElement->FindAttribute("name");
    const tinyxml2::XMLAttribute* tileWidthAttribute = tileSetNameAttribute->Next();
    const tinyxml2::XMLAttribute* tileHeightAttribute = tileWidthAttribute->Next();
    const tinyxml2::XMLAttribute* tileCountAttribute = tileHeightAttribute->Next();
    const tinyxml2::XMLAttribute* columnsAttribute = tileCountAttribute->Next();
    const tinyxml2::XMLAttribute* tileSetSource = imageElement->FirstAttribute();
    name = tileSetNameAttribute->Value();
    tileWidth = atoi(tileWidthAttribute->Value());
    tileHeight = atoi(tileHeightAttribute->Value());
    tileCount = atoi(tileCountAttribute->Value());
    columns = atoi(columnsAttribute->Value());
    std::string imageSource = "Tilesets/";
    std::string imageSource2 = tileSetSource->Value();
    texture.loadFromFile(imageSource + imageSource2);
    sprite.setTexture(texture);

}
