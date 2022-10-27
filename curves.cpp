
#include <iostream>
#include <memory>
#include <math.h>
#include "curves.h"

#define EPSILON 0.000006

void Point::display(){
    /*if ( point_x < EPSILON) point_x = 0;
    if ( point_y < EPSILON) point_y = 0;
    if ( point_z < EPSILON) point_z = 0;*/
    //std::cout << point_x << "\t\t\t" << point_y << "\t\t\t" << point_z << std::endl;
    printf("\t%.6f\t%.6f\t%.6f\n",point_x,point_y,point_z);
}

std::vector<Point> Curves::getDerivativeVector() {
    std::vector<Point> temp_vector;
    for (float t = 0; t < 2* M_PI; t=t+M_PI/15) {
        temp_vector.push_back(getDerivativePoints(t));
    }
    return temp_vector;
}

bool Curves::sortByRadii( const std::shared_ptr<Curves>& curve1, const std::shared_ptr<Curves>& curve2) {
    return curve1->getRadii() < curve2->getRadii();
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

void Circles::change_data() {
    radius = radius * 10;
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

void Ellipses::change_data() {
    radius_X = radius_X * 10;
    radius_Y = radius_Y * 10;
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

void Helixes::change_data() {
    radius = radius * 10;
    step = step * 10;
}

float Helixes::getRadii() {
    return radius;
}