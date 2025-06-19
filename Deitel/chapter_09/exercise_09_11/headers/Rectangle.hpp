#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

class Rectangle
{
public:
    Rectangle(const double length = 1.0, const double width = 1.0);
    
    void setLength(const double length);
    void setWidth(const double width);
    
    double getLength();
    double getWidth();
    
    double perimeter();
    double area();

private:
    double length_;
    double width_;
};

#endif

