#include <iostream>
#include <SFML/Graphics.hpp>
#include <Vector2.hpp>

using namespace std;

int main()
{

    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Sneak" );
    sf::Event event;

    Vector2f laughin(1.0f, 1.0f);
    Vector2f At(1, 1);

    Vector2f You = laughin + At;

    You.PrintData( Cartesian );

    while ( window.isOpen() ) {
        while ( window.pollEvent( event ) ) {
            if ( event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }
}
