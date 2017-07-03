#ifndef COLLISIONDETECTION_HPP_INCLUDED
#define COLLISIONDETECTION_HPP_INCLUDED

bool axisAlignedBoundingBoxes( Rectangle& box1, Rectangle& box2 ) {

    if ( box1.Position.x <= box2.Position.x + box2.Width && box1.Position.x >= box2.Position.x ) {
        if( box1.Position.y <= box2.Position.y + box2.Height && box1.Position.y >= box2.Position.y ) {
            return true;
        }
    }

}
#endif // COLLISIONDETECTION_HPP_INCLUDED
