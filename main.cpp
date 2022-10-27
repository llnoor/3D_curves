

//#include "curves.h"
#include "tasks_curves.h"

int main() {
    Tasks all_tasks;
    all_tasks.task1();
    all_tasks.task2();
    all_tasks.task3();
    all_tasks.task4();
    all_tasks.task5();
    all_tasks.task6();

    
    /*srand(time(NULL));
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
        printf("\nNumber_of_curve: %d Type: %d Radius: %.6f\n", i, second_container[i]->getType(), second_container[i]->getRadii() );
        printf("Point           :\t");
        second_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        second_container[i]->getDerivativePoints(M_PI/4).display();
    }

    std::sort(second_container.begin(), second_container.end(), Curves::sortByRadii );

    printf("\nsorted second_container:\n");

    for(int i=0; i < (int) second_container.size(); i++) {
        printf("\nNumber_of_curve: %d Type: %d Radius: %.6f\n", i, second_container[i]->getType(), second_container[i]->getRadii() );
        printf("Point           :\t");
        second_container[i]->getPoints(M_PI/4).display();
        printf("DerivativePoints:\t");
        second_container[i]->getDerivativePoints(M_PI/4).display();
    }

    float sum_of_radii = 0;
    std::for_each(second_container.begin(), second_container.end(), [&](std::shared_ptr<Curves>& temp_curve){
        sum_of_radii += temp_curve->getRadii();
    });

    std::cout << "sum_of_radii:" << sum_of_radii << std::endl;*/

    return 0;
}
