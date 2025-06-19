#ifndef __POINT_HPP__
#define __POINT_HPP__

class Point
{
public:
    Point(const double x = 0.0, const double y = 0.0);

    void setX(const double x);
    void setY(const double y);
    
    double getX() const;
    double getY() const;
private:
    double x_;
    double y_;
};

#endif

