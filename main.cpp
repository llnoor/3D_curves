#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

#include "curves.h"

enum enum_curves {
    circle,
    ellipse,
    helixe
};

float rand_float(float, float);

/*bool sortByRadii( const std::shared_ptr<Curves>& curve1, const std::shared_ptr<Curves>& curve2) {
    return curve1->getRadii() < curve2->getRadii();
}*/
 

int main() {
    srand(time(NULL));
    
    //int type = (int) rand_float(0,3);
    //int radius = rand_float(0,100);

    std::vector<std::shared_ptr<Curves>> first_container;

    int number_curves = 10;
    
    for (int i = 0; i < number_curves; i++) {
        int type = (int) rand_float(0,3);
        switch (type){
        case circle:
            first_container.push_back(std::make_shared<Circles>(circle, rand_float(0, 10)));
            break;
        case ellipse:
            first_container.push_back(std::make_shared<Ellipses>(ellipse, rand_float(0, 10), rand_float(0, 10)));
            break;
        case helixe:
            first_container.push_back(std::make_shared<Helixes>(helixe, rand_float(0, 10), rand_float(0, 10)));
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

    std::vector<std::shared_ptr<Curves>> second_container;
    for(int i=0; i < (int) first_container.size(); i++) {
        if ( 0 == first_container[i]->getType() ) {
            second_container.push_back(first_container[i]);
        }
    }

    printf("\nsecond_container:\n");

    for(int i=0; i < (int) second_container.size(); i++) {
        printf("\nNumber_of_curve: %d Type: %d\n", i, second_container[i]->getType());
        printf("Point           :\t");
        second_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        second_container[i]->getDerivativePoints(M_PI/4).display();
    }

    std::sort(second_container.begin(), second_container.end(), Curves::sortByRadii );

    printf("\nsorted second_container:\n");

    for(int i=0; i < (int) second_container.size(); i++) {
        printf("\nNumber_of_curve: %d Type: %d\n", i, second_container[i]->getType());
        printf("Point           :\t");
        second_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        second_container[i]->getDerivativePoints(M_PI/4).display();
    }

    //sum_of_elems = std::accumulate(vector.begin(), vector.end(), decltype(vector)::value_type(0));
    //float sum_of_radii = std::accumulate(second_container.begin(), second_container.end(), 0);

    //float sum_of_radii = std::accumulate(second_container.begin(), second_container.end(), second_container );


    //std::cout << "sum_of_radii:" << sum_of_radii << std::endl;

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