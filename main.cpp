#include <iostream>
#include "curves.h"

enum enum_curves {
    circle,
    ellipse,
    helixe
};

int main() {
    Ellipses n_ellipses(ellipse,1,1);
    
    for (float i=0; i<3.14; i=i+0.01) {
        Point first_point(n_ellipses.getPoints(i));
        first_point.display();
    }
    return 0;
}