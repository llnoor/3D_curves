
#include <iostream>
#include <math.h>
#include "curves.h"

#define EPSILON 0.000006

void Point::display(){
    /*if ( point_x < EPSILON) point_x = 0;
    if ( point_y < EPSILON) point_y = 0;
    if ( point_z < EPSILON) point_z = 0;*/
    std::cout << point_x << ":" << point_y << ":" << point_z << std::endl;
}

Point Circles::getPoints(float t) {
    float x = radius*cos(t);
    float y = radius*sin(t);
    float z = 0.0;
    return Point(x,y,z);
}

Point Ellipses::getPoints(float t) {
    float x = radius_X*cos(t);
    float y = radius_Y*sin(t);
    float z = 0.0;
    return Point(x,y,z);
}

Point Helixes::getPoints(float t){
    float x = radius*cos(t);
    float y = radius*sin(t);
    float z = step*(t/(2*M_PI));
    return Point(x,y,z);
}

