#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <Vector2.hpp>

template <class T>
struct Rectangle{

    T Position;
    T Dimensions;
    float Rotation;

};

typedef Rectangle<Vector2f> RectangleFloat;
typedef Rectangle<Vector2i> RectangleInt;
typedef Rectangle<Vector2d> RectangleDouble;

#endif // RECTANGLE_H_INCLUDED
