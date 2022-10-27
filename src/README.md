# 3D_curves


leaks were checked by 
<code> valgrind --leak-check=full ./main.out </code>

test programm test_curves.cpp was used to check functions of the programm
<code> functions: getPoints of circles and e.g. </code>


first derivatives:

Circles:
first derivative of radius = 0, because r = const
first derivative of t (it is like angle) = 


So we have 3D point: x, y, z;
For me 3D vector means vector of 3D points. It means that we should return vector of Points:
dx/dt, dy/dt, dz/dt. 

For Circles we have:
x = R cos(t) here t is angle form 0 to 2 PI 
y = R sin(t)
for circles R=const
dx/dt = -R sin(t)
dy/dt = R cos(t)
For PI/4 we have
dx/dt (PI/4) = -R sqrt(2)/2
dy/dt (PI/4)  = R sqrt(2)/2
It means that at point (PI/4) x will be decrease, y will be increase (it is a derivative, we checked it, see picture 1, point PI/4) 
dz/dt = 0

For Ellipses we have almost the same:
x = a cos(t)
y = b sin(t)
a, b it is radii for ellipse
dx/dt = -a sin(t)
dy/dt = b cos(t)
dz/dt = 0



Also we can return d(ro)/dt, d(angle)/dt, but it will work olny for circles and ellipses, but helixes (they recuire dz/dt).

I decided stay dx/dt, dy/dt, dz/dt.
I will change angle from 0 to 2 PI or 4 PI with step PI/16 (it tunable).

Why?
We have equation C(t+2PI)= C(t) + {0,0,step}
It means than we have leniar dependanse of z from t. We do not have any.

So z=step*t/2PI
dz/dt = step/2PI?


4. Populate a second container that would contain only circles from the first container. Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
How can we check it?
We can do something with second container. This opertion should effect to data. And we can see it throght first container.