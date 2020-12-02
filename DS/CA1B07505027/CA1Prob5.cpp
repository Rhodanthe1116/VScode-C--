/*
    A rectangle class

    @Author:       HAN-WEN, CHANG
    @ID:           B075050527
    @Department:   Engineering Science and Ocean Engineering
    @Affiliation:  National Taiwan University
*/
#include<iostream>
using namespace std;

class rectangle
{
private:
    double width;
    double length;
    double perimeter;
    double area;

public:
    // Constructor, automatically compute the perimeter and area once it is OK.
    rectangle(double wd, double lg)
    {
        width = wd;
        length = lg;
        perimeter = 2 * (width + length);
        area = width * length;
    };
    // Set the dimension and automatically update the perimeter and area.
    void setDimension(double wd, double lg)
    {
        width = wd;
        length = lg;
        perimeter = 2 * (width + length);
        area = width * length;
    };
    // Set the width and automatically update the perimeter and area.
    void setWidth(double wd)
    {
        width = wd;
        perimeter = 2 * (width + length);
        area = width * length;
    };
    // Set the length and automatically update the perimeter and area.
    void setLength(double lg)
    {
        length = lg;
        perimeter = 2 * (width + length);
        area = width * length;
    };
    // Return the width of the rectangle.
    double getWidth()
    {
        return width;
    };
    // Return the length of the rectangle.
    double getLength()
    {
        return length;
    };
    // Return the perimeter of the rectangle.
    double getPerimeter()
    {
        return perimeter;
    };
    // Return the area of the rectangle.
    double getArea()
    {
        return area;
    };
    // True, if width = length.
    bool isSquare()
    {
        return width == length ? 1 : 0;
    };
};
