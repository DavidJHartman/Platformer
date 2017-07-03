#ifndef VECTOR2_HPP_INCLUDED
#define VECTOR2_HPP_INCLUDED
#include <math.h>


enum VectorType {
    Polar,
    Cartesian
};

template <class T>
class Vector2 {

public:
    T x, y;
    Vector2( T x, T y ) { this->x = x; this->y = y; }
    Vector2( ) { x = 0; y = 0; }
    ~Vector2( ){ }

    //////////////////////
    // MEMBER FUNCTIONS //
    //////////////////////

    void PrintData ( VectorType type ) {
        if ( type == Polar ) {
            std::cout << "Polar Vector Data: \n" << "magnitude: \t" << sqrt( x * x + y * y ) << "\nAngle: \t" << atan( y / x ) * ( 180 / 3.14159 ) << std::endl;
        }
        if ( type == Cartesian ) {
            std::cout << "Cartesian Vector Data: \nX: " << x << "\tY: " << y << std::endl << std::endl;
        }
    }

    //////////////////////////
    // OVERLOADED OPERATORS //
    //////////////////////////

    // Addition operators
    Vector2<T> operator + ( Vector2& V ) {
        return Vector2( x + V.x, y + V.y );
    }
    void operator += ( Vector2& V ) {
        x += x; y += y;
    }

    // Subtraction operators
    Vector2<T> operator - ( Vector2& V ) {
        return Vector2( x - V.x, y - V.y );
    }
    void operator -= ( Vector2& V ) {
        x -= x; y -= y;
    }

    // Scalar operators
    Vector2<T> operator * ( T Scalar ) {
        return Vector2( x * Scalar, y * Scalar );
    }
    Vector2<T> operator / ( T Scalar ) {
        return Vector2( x / Scalar, y / Scalar );
    }
    void operator *= ( T Scalar ) {
        x *= Scalar; y *= Scalar;
    }
    void operator /= ( T Scalar ) {
        x /= Scalar; y /= Scalar;
    }
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

#endif // VECTOR2_HPP_INCLUDED
