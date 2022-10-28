#include <iostream>
#include <memory>
#include <math.h>
#include "curves.h"

void Point::display(){
    //std::cout << point_x << point_y << point_z << std::endl; 
    printf("\t%.6f\t%.6f\t%.6f\n",point_x,point_y,point_z);  // here precision have sence, so printf
}

std::vector<Point> Curves::getDerivativeVector() {
    std::vector<Point> temp_vector;
    for (float t = 0; t < 2* M_PI; t=t+2*M_PI/7) {
        temp_vector.push_back(getDerivativePoints(t));
    }
    return temp_vector;
}

bool Curves::sortByRadii( const std::shared_ptr<Curves>& curve1, const std::shared_ptr<Curves>& curve2) {
    return curve1->getRadii() < curve2->getRadii();
}

int Curves::getType() {
    return type;
}

Point Circles::getPoints(float t) {
    float x = radius*cos(t);
    float y = radius*sin(t);
    float z = 0.0;
    return Point(x,y,z);
}

Point Circles::getDerivativePoints(float t) {
    float x = - radius*sin(t);
    float y = radius*cos(t);
    float z = 0.0;
    return Point(x,y,z);
}

float Circles::getRadii() {
    return radius;
}

Point Ellipses::getPoints(float t) {
    float x = radius_X*cos(t);
    float y = radius_Y*sin(t);
    float z = 0.0;
    return Point(x,y,z);
}

Point Ellipses::getDerivativePoints(float t) {
    float x = - radius_X*sin(t);
    float y = radius_Y*cos(t);
    float z = 0.0;
    return Point(x,y,z);
}

float Ellipses::getRadii() {
    return radius_X*radius_Y;  // like area of ellipses / M_PI
}

Point Helixes::getPoints(float t){
    float x = radius*cos(t);
    float y = radius*sin(t);
    float z = step*(t/(2*M_PI));
    return Point(x,y,z);
}

Point Helixes::getDerivativePoints(float t) {
    float x = - radius*sin(t);
    float y = radius*cos(t);
    float z = step/(2*M_PI);
    return Point(x,y,z);
}

float Helixes::getRadii() {
    return radius;
}
