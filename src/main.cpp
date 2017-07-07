#include <iostream>
#include <SFML/Graphics.hpp>
#include <Physics/CollisionDetection.hpp>

using namespace std;

int main()
{

    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Sneak" );
    sf::Event event;

    ////////////////////////
    // TESTING PLAYGROUND //
    ////////////////////////

    Vector2f a ( 2.0f, 2.0f);
    Vector2f b ( 1.0f, 0.0f);

    a = projectVector(a, b);

    a.PrintData( Cartesian );

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
    return 0;
}
