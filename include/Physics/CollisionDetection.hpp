#ifndef COLLISIONDETECTION_HPP_INCLUDED
#define COLLISIONDETECTION_HPP_INCLUDED

#include <Primitives/Rectangle.h>
#include <Primitives/Circle.hpp>

template <class T>
bool axisAlignedBoundingBoxCollision( Rectangle<T>& box1, Rectangle<T>& box2 ) {

    if ( box1.Position.x + box1.HalfDimensions.x < box2.Position.x - box2.HalfDimensions.x || box1.Position.x - box1.HalfDimensions.x > box2.Position.x + box2.HalfDimensions.x ){ return false;}
    if ( box1.Position.y - box1.HalfDimensions.y > box2.Position.y + box2.HalfDimensions.y || box1.Position.y + box1.HalfDimensions.y < box2.Position.y - box2.HalfDimensions.y ){ return false;}

    return true;
}

template <class T>
bool circularCollision( Circle<T>& cir1, Circle<T>& cir2 ) {

    if ( sqrt(cir1.Position.x - cir2.Position.x + cir1.Position.y - cir2.Position.y) > cir1.Radius - cir2.Radius ){ return false; }

    return true;
}

template <class T>
bool axisAllignedBoundingBoxContains( Vector2f point, Rectangle<T>& box ) {
    if ( box.Position.x - box.HalfDimensions.x > point.x || box.Position.x + box.HalfDimensions.x < point.x )return false;
    if ( box.Position.y - box.HalfDimensions.y > point.y || box.Position.y + box.HalfDimensions.y < point.y )return false;
    return true;
}
#endif // COLLISIONDETECTION_HPP_INCLUDED
