#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED

template <class T>
class Circle{

    T Position;
    float Radius

};

typedef Circle<Vector2f> CircleFloat;
typedef Circle<Vector2i> CircleInt;
typedef Circle<Vector2d> CircleDouble;

#endif // CIRCLE_HPP_INCLUDED
