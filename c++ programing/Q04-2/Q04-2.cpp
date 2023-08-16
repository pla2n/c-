#include <iostream>
using std::cout;
using std::endl;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y)
    { }
    void ShowPointInfo() const
    {
        cout << "[" << xpos << "," << ypos << "]" << endl;
    }
};

class Circle
{
private:
    int radious;
    Point center;
public:
    Circle(int x, int y, int r) : center(x, y)
    {
        radious = r;
    }
    void ShowCircleInfo() const
    {
        cout << "radius:" << radious << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle incircle;
    Circle outcircle;
public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2) :incircle(x1, y1, r1), outcircle(x2, y2, r2)
    { }
    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        incircle.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        outcircle.ShowCircleInfo();
    }
};

int main()
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}