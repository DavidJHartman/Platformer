#ifndef VECTORMATH_HPP_INCLUDED
#define VECTORMATH_HPP_INCLUDED
#include <Vector2.hpp>

template <class T>
double dotProduct( Vector2<T>& vec1, Vector2<T>& vec2 ) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

template <class T>
double magnitude( Vector2<T>& vec ) {
    return sqrt( vec.x * vec.x + vec.y * vec.y );
}

template <class T>
void normalizeVector( Vector2<T>& vec ) {
    vec/=magnitude(vec);
}

template <class T>
Vector2<T> giveNormalizedVector( Vector2<T>& vec ) {
    return Vector2<T>(vec/magnitude(vec));
}

template <class T>
void rotateVector( Vector2<T>& vec, float angle ) {
    vec = Vector2<T>( vec.x * cos( angle ) - vec.y * sin( angle ), vec.x * sin( angle ) + vec.y * cos( angle ) );
}

#endif // VECTORMATH_HPP_INCLUDED
