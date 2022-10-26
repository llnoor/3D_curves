#include <iostream>
#include <memory>
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

    std::vector<std::unique_ptr<Curves>> first_container;
    
    first_container.push_back(std::make_unique<Circles>(circle, 1));

    /*for (float k = 0 ; k < (2*M_PI); k=k+M_PI/15) {
        //printf("Point          :\t");
        //first_container[0]->getPoints(k).display();
        printf("t: %.2f\t: ", k);
        first_container[0]->getDerivativePoints(k).display();
    }

    printf("\nvector:\n");

    std::vector<Point> temp_vector2;
    temp_vector2 = first_container[0]->getDerivativeVector();
    for(int i=0; i < (int) temp_vector2.size(); i++) {
        printf("i: %d\t: ", i);
        temp_vector2.at(i).display();
    }*/


    int number_curves = 20;
    
    for (int i = 0; i < number_curves; i++) {
        int type = (int) rand_float(0,3); // random curve with random 
        switch (type){
        case circle:
            first_container.push_back(std::make_unique<Circles>(circle, rand_float(0, 10)));
            break;
        case ellipse:
            first_container.push_back(std::make_unique<Ellipses>(ellipse, rand_float(0, 10), rand_float(0, 10)));
            break;
        case helixe:
            first_container.push_back(std::make_unique<Helixes>(helixe, rand_float(0, 10), rand_float(0, 10)));
            break;
        }
    }

    for(int i=0; i < (int) first_container.size(); i++) {
        printf("\nNumber_of_curve: %d Type: %d\n", i, first_container[i]->getType());
        printf("Point           :\t");
        first_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        first_container[i]->getDerivativePoints(M_PI/4).display();
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