#include <iostream>

#include <Tilemap/TileMap.hpp>
#include <UI/UI.hpp>

void hover_function(void** objectsInteractedWith, ButtonState* state) {std::cout << "neato";}

int main()
{

    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Sneak" );
    sf::View gameView;
    window.setView(gameView);
    sf::Event event;

    ////////////////////////
    // TESTING PLAYGROUND //
    ////////////////////////

    TileMap newMap;
    newMap.loadMap("Maps/TestMap.tmx");

    UIObject newObject(Vector2f(0,0), Vector2f(20,20));
    //newObject.setHoverFunction(hover_function);
    newObject.hover_function = &hover_function;

    ////////////////////////
    //   STOP PLAYING!    //
    ////////////////////////

    while ( window.isOpen() ) {

        //gameView.move(1,1);
        //window.setView(gameView);

        while ( window.pollEvent( event ) ) {
            if ( event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Red);

        newObject.interaction(sf::Vector2f(10,10), false);

        newMap.Render(window);

        window.display();
    }
    return 0;
}
