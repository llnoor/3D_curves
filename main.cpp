#include <iostream>
#include <vector>
#include <math.h>

#include "curves.h"

enum enum_curves {
    circle,
    ellipse,
    helixe
};

float rand_float(float, float);

int main() {
    srand(time(NULL));
    
    //int type = (int) rand_float(0,3);
    //int radius = rand_float(0,100);

    std::vector<Curves*> first_container;
    //int number_curves = 3;
    
    for (int i = 0; i < 10; i++) {
        int type = (int) rand_float(0,3);
        switch (type){
        case circle:
            first_container.push_back(new Circles(circle, 1));
            break;
        case ellipse:
            first_container.push_back(new Ellipses(ellipse, 1, 2));
            break;
        case helixe:
            first_container.push_back(new Helixes(helixe, 1, 1));
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        std::cout << "type:" << first_container[i]->getType() << std::endl;
        for (float i = 0 ; i < (2*M_PI); i=i+M_PI/16) {
            first_container[i]->getPoints(i).display();
        }
    }

    

    /*for (float i = 0 ; i < (2*M_PI); i=i+M_PI/4) {
        std::cout << "i:" << i << " cos:" << cos(i) << std::endl;
    }*/


    return 0;
}

float rand_float(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}