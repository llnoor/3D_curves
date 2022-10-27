#ifndef TASKS_CURVES_H
#define TASKS_CURVES_H

#include <memory>
#include <vector>
#include "curves.h"

enum enum_curves {
    circle,
    ellipse,
    helixe
};

class Tasks {
public:
    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();
    void task8();
    float rand_float(float, float);
private:
    int type;
    float sum_of_radii;
    std::vector<std::shared_ptr<Curves>> first_container;
    std::vector<std::shared_ptr<Curves>> second_container;
};

#endif  // TASKS_CURVES_H