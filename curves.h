#ifndef CURVES_H
#define CURVES_H

class Point {
    float point_x;
    float point_y;
    float point_z;
public:
    Point(float in_x, float in_y, float in_z): point_x(in_x), point_y(in_y), point_z(in_z) {}
    void display();
};

class Curves
{
public:
    Curves(int in_type): type(in_type) {}
    virtual Point getPoints(float) = 0; 
protected:
    int type;
};

class Circles : public Curves
{
public:
    Circles (int in_type, float in_radius)
    :Curves(in_type), radius(in_radius) {}
    Point getPoints(float t) override;
private:
    float radius;
};

class Ellipses : public Curves
{
public:
    Ellipses (int in_type, float in_radius_X, float in_radius_Y)
    :Curves(in_type), radius_X(in_radius_X), radius_Y(in_radius_Y) {}
    Point getPoints(float t) override;
private:
    float radius_X;
    float radius_Y;
};

class Helixes : public Curves
{
public:
    Helixes (int in_type, float in_radius, float in_step)
    :Curves(in_type), radius(in_radius), step(in_step) {}
    Point getPoints(float t) override;
private:
    float radius;
    float step;
};

#endif  // CURVES_H