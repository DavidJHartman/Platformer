#include <iostream>

#include <Tilemap/TileMap.hpp>
#include <UI/UI.hpp>

int main()
{

    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Sneak" );
    sf::View gameView;
    window.setView(gameView);
    sf::Event event;

    ////////////////////////
    // TESTING PLAYGROUND //
    ////////////////////////



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

        window.display();
    }
    return 0;
}
