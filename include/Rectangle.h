#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

template <class T>
struct Rectangle{

    T Position;
    T Width;
    T Height;
    float Rotation;

};

typedef Rectangle<Vector2f> RectangleFloat;
typedef Rectangle<Vector2i> RectangleInt;
typedef Rectangle<Vector2d> RectangleDouble;

#endif // RECTANGLE_H_INCLUDED
