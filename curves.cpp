
#include <iostream>
#include <math.h>

#include "curves.h"

void Point::display(){
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
    float z = 0.0;
    return Point(x,y,z);
}

