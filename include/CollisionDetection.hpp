#ifndef COLLISIONDETECTION_HPP_INCLUDED
#define COLLISIONDETECTION_HPP_INCLUDED

#include <Rectangle.h>

template <class T>
bool axisAlignedBoundingBoxes( Rectangle<T>& box1, Rectangle<T>& box2 ) {

    if ( box1.Position.x + box1.Dimensions.x < box2.Position.x || box1.Position.x > box2.Position.x + box2.Dimensions.x ){ return false;}
    if ( box1.Position.y - box1.Dimensions.y > box2.Position.y || box1.Position.y < box2.Position.y - box2.Dimensions.y ){ return false;}

    return true;
}
#endif // COLLISIONDETECTION_HPP_INCLUDED
