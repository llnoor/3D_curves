#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <math.h>
#include "tasks_curves.h"

#define NUMBER_CURVES 10

void Tasks::task1() {
    std::cout << "Task1:" << std::endl;
    first_container.push_back(std::make_shared<Circles>(circle, rand_float(0, 10)));
    first_container.push_back(std::make_shared<Ellipses>(ellipse, rand_float(0, 10), rand_float(0, 10)));
    first_container.push_back(std::make_shared<Helixes>(helixe, rand_float(0, 10), rand_float(0, 10)));
    std::cout << "Test_Task1:" << std::endl;
    std::for_each(first_container.begin(), first_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        std::cout << "Point:" << std::endl;
        temp_curve->getPoints(M_PI/4).display();
        std::cout << "DerivativeVector:" << std::endl; 
        std::vector<Point> temp_vector = temp_curve->getDerivativeVector();
        std::for_each(temp_vector.begin(), temp_vector.end(), [&](Point& temp_point){
            temp_point.display();
        });
    });
    first_container.clear(); // shared_ptr and the objects will be automatically de-allocated 
    std::cout << "DONE" << std::endl;
}

void Tasks::task2() {
    std::cout << "Task2:" << std::endl;
    for (int i = 0; i < NUMBER_CURVES; i++) {
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
    std::cout << "Task2 will be tested in Task3" << std::endl;
}

void Tasks::task3() {
    std::cout << "Task3:" << std::endl;
    std::for_each(first_container.begin(), first_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        printf("Point at M_PI/4          :\t");
        temp_curve->getPoints(M_PI/4).display();
        printf("DerivativePoint at M_PI/4:\t");
        temp_curve->getDerivativePoints(M_PI/4).display();
    });
    std::cout << "DONE" << std::endl;
}

void Tasks::task4() {
    std::cout << "Task4:" << std::endl;
    std::for_each(first_container.begin(), first_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        if ( temp_curve->getType() == circle ) {
            second_container.push_back(temp_curve);
        }
    });
    std::cout << "Task4 should contain only circles (i.e. at M_PI/4: x = y, z = 0):" << std::endl;
    std::for_each(second_container.begin(), second_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        printf("Point at M_PI/4:\t");
        temp_curve->getPoints(M_PI/4).display();
    });
    std::cout << "DONE" << std::endl;
}

void Tasks::task5() {
    std::cout << "Task5:" << std::endl;
    std::sort(second_container.begin(), second_container.end(), Curves::sortByRadii );
    std::cout << "Test_Task5: first element " 
    "has the smallest radius, the last - the greatest" << std::endl;
    std::for_each(second_container.begin(), second_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        //printf("Radius: %.6f\n", temp_curve->getRadii() );
        std::cout << "Radius: " << temp_curve->getRadii() << std::endl;
    });
    std::cout << "DONE" << std::endl;
}

void Tasks::task6() {
    std::cout << "Task6:" << std::endl;
    std::for_each(second_container.begin(), second_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        sum_of_radii += temp_curve->getRadii();
    });
    std::cout << "Total sum of radii:" <<  sum_of_radii << std::endl;
    std::cout << "DONE" << std::endl;
}

float Tasks::rand_float(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}