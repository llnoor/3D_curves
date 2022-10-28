# 3D_curves

## Programming Part: ##
**Task1**: 
Program have three general classes:
1. Curves (to work with 3D geometric curves)
2. Points (to display 3D points)
3. Task (to check Curves class)

And subclasses:
1. Circles
2. Ellipses
3. Helixes

There are getPoints() return 3D Points
getDerivativeVector() return vector of 3D Points (to populate this vector we change t (angle) from 0 to 2 PI with step PI/7)

**Task2**: For populating containers I used smart points. (in this case shared_ptr was used, because we should share this points in task 4).

**Task3**: For printing coordinates of points and derivatives of all curves in the container at t=PI/4 I used function display() from Point class. For iterating over all elements of the vector std::for_each (C++11) was used.

**Task4**: I populated second_container with using std::for_each (C++11).
To be sure that it is points, I tried change elements from second_container points. Then I checked elements from first_container points. They have changed. (In release program don't have this function).

**Task5**: Second_container was sorted by std::sort (C++11) using function Curves::sortByRadii, which compare radii of curves.

**Task6**: To find Total sum of radii second_container was iterated over all elements std::for_each (C++11). 

**Task7**: Class Curves was splitted to dynamic library curves.so. To check this task run make with target "task7"

Leaks were checked by valgrind:
```
valgrind --leak-check=full --undef-value-errors=no ./main.out
```

## Mathematics part: ##
We have #3D point#: x, y, z;
For me #Derivative 3D vector# means vector of 3D points. It means that we should return vector of Points: dx/dt, dy/dt, dz/dt. 

First try to find equation for **Circles**:
In polar system: r (or "ro") = const, t (angle) changes from 0 ti 2*M_PI
We should find 3D points: x, y, z
```
x = R cos(t), where R = radius
y = R sin(t)
z = 0
```

So, first derivative function for **Circles**:
```
dx/dt = -R sin(t) (R=const)
dy/dt = R cos(t)
dz/dt = 0
```

At t=PI/4 we have
```
x (PI/4) = R sqrt(2)/2
y (PI/4) = R sqrt(2)/2
z (PI/4) = 0
dx/dt (PI/4) = -R sqrt(2)/2
dy/dt (PI/4) = R sqrt(2)/2
dz/dt (PI/4) = 0
```
It means that at point (PI/4) x will be decrease (because dx/dt<0), y will be increase (because dy/dt>0).

Note, at t=PI/4 x = -dx/dt, y = dy/dt (we can use it to check result).

For **Ellipses** we have almost the same:
```
x = a cos(t)
y = b sin(t)
z = 0
```
a, b are radii for ellipse

Derivatives:
```
dx/dt = -a sin(t) (a = const)
dy/dt = b cos(t)
dz/dt = 0
```

At t=PI/4 we have
```
x (PI/4) = a sqrt(2)/2,
y (PI/4) = b sqrt(2)/2,
z (PI/4) = 0.
dx/dt (PI/4) = -a sqrt(2)/2,
dy/dt (PI/4) = b sqrt(2)/2,
dz/dt (PI/4) = 0.
```
Note, at t=PI/4, x = -dx/dt, y = dy/dt.

For **Helixes** we have almost the same for the circle, and dependence of z on t:
```
x = R cos(t),
y = R sin(t),
z = step*t/2PI.
```
(We have equation C(t+2PI)= C(t) + {0,0,step}.
It means than we have linear dependence of z on t. 
At t = 2PI,  z(2PI) = step.)

Derivatives:
```
dx/dt = -R sin(t), (R=const),
dy/dt = R cos(t),
dz/dt = step/2PI.
```

At t=PI/4 we have
```
x (PI/4) = a sqrt(2)/2,
y (PI/4) = b sqrt(2)/2,
z (PI/4) = step/8.
dx/dt (PI/4) = -a sqrt(2)/2,
dy/dt (PI/4) = b sqrt(2)/2,
dz/dt (PI/4) = step/2PI.
```
Note, at t=PI/4 x = -dx/dt, y = dy/dt, z = (PI/4) * dz/dt.