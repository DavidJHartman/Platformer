#include <iostream>
#include <SFML/Graphics.hpp>
#include <Vector2.hpp>

using namespace std;

int main()
{

    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Sneak" );
    sf::Event event;

    ////////////////////////
    // TESTING PLAYGROUND //
    ////////////////////////


    ////////////////////////
    //   STOP PLAYING!    //
    ////////////////////////

    while ( window.isOpen() ) {
        while ( window.pollEvent( event ) ) {
            if ( event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }
}
