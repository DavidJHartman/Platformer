#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <Primitives/VectorMath.hpp>

template <class T>
class Rectangle{

public:

    T Position;
    T HalfDimensions;
    float Rotation;

};

typedef Rectangle<Vector2f> RectangleFloat;
typedef Rectangle<Vector2i> RectangleInt;
typedef Rectangle<Vector2d> RectangleDouble;

#endif // RECTANGLE_H_INCLUDED
