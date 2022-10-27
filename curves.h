#ifndef CURVES_H
#define CURVES_H

#include <vector>

class Point {
    float point_x;
    float point_y;
    float point_z;
public:
    Point(float in_x, float in_y, float in_z): point_x(in_x), point_y(in_y), point_z(in_z) {}
    void display();
    /*float getPointX();
    float getPointY();
    float getPointZ();*/
};

class Curves
{
public:
    Curves(int in_type): type(in_type) {}
    virtual Point getPoints(float) = 0;
    virtual Point getDerivativePoints(float) = 0;
    virtual void change_data() = 0;
    std::vector<Point> getDerivativeVector();
    int getType() {
        return type;
    }

    static bool sortByRadii( const std::shared_ptr<Curves>&, const std::shared_ptr<Curves>&);

    //bool operator()( const std::shared_ptr<Curves>& curve1, const std::shared_ptr<Curves>& curve2) const ;
    virtual float getRadii() = 0;
    operator int() { return this->getRadii(); }
    //operator + {return Curves(this->seconds + c2.seconds);} 
protected:
    int type;
};

class Circles : public Curves
{
public:
    Circles (int in_type, float in_radius)
    :Curves(in_type), radius(in_radius) {}
    Point getPoints(float t) override;
    Point getDerivativePoints(float t) override;
    void change_data() override;
    float getRadii() override;
private:
    float radius;
};

class Ellipses : public Curves
{
public:
    Ellipses (int in_type, float in_radius_X, float in_radius_Y)
    :Curves(in_type), radius_X(in_radius_X), radius_Y(in_radius_Y) {}
    Point getPoints(float t) override;
    Point getDerivativePoints(float t) override;
    void change_data() override;
    float getRadii() override;
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
    Point getDerivativePoints(float t) override;
    void change_data() override;
    float getRadii() override;
private:
    float radius;
    float step;
};

#endif  // CURVES_H