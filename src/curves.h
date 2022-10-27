#ifndef CURVES_H
#define CURVES_H

#include <vector>

class Point {
public:
    Point(float in_x, float in_y, float in_z): 
        point_x(in_x), point_y(in_y), point_z(in_z) {}
    void display();
private:
    float point_x;
    float point_y;
    float point_z;
};

class Curves {
public:
    Curves(int in_type): type(in_type) {}
    int getType();
    virtual Point getPoints(float) = 0;
    virtual Point getDerivativePoints(float) = 0;
    virtual float getRadii() = 0;
    std::vector<Point> getDerivativeVector();
    static bool sortByRadii (const std::shared_ptr<Curves>&, 
        const std::shared_ptr<Curves>&);
protected:
    int type;
};

class Circles : public Curves
{
public:
    Circles (int in_type, float in_radius):Curves(in_type), 
        radius( in_radius > 0 ? in_radius : 0 ) {}
    Point getPoints(float t) override;
    Point getDerivativePoints(float t) override;
    float getRadii() override;
private:
    float radius;
};

class Ellipses : public Curves {
public:
    Ellipses (int in_type, float in_radius_X, float in_radius_Y):Curves(in_type), 
        radius_X( in_radius_X > 0 ? in_radius_X : 0 ), 
        radius_Y( in_radius_Y > 0 ? in_radius_Y : 0 ) {}
    Point getPoints(float t) override;
    Point getDerivativePoints(float t) override;
    float getRadii() override;
private:
    float radius_X;
    float radius_Y;
};

class Helixes : public Curves {
public:
    Helixes (int in_type, float in_radius, float in_step):Curves(in_type), 
        radius( in_radius > 0 ? in_radius : 0 ), step( in_step > 0 ? in_step : 0 ) {}
    Point getPoints(float t) override;
    Point getDerivativePoints(float t) override;
    float getRadii() override;
private:
    float radius;
    float step;
};

#endif  // CURVES_H
