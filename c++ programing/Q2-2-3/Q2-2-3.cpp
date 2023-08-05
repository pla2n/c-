#include <iostream>

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main()
{
    Point* p1 = new Point;
    Point* p2 = new Point;
    p1->xpos = 5; p1->ypos = 10;
    p2->xpos = 10; p2->ypos = 20;

    Point &pref = PntAdder(*p1, *p2);
    std::cout << "x: " << pref.xpos << std::endl;
    std::cout << "y: " << pref.ypos << std::endl;

    delete &pref;
    delete p1;
    delete p2;
}

Point& PntAdder(const Point& p1, const Point& p2)
{
    Point* pptr = new Point;
    pptr->xpos = p1.xpos + p2.xpos;
    pptr->ypos = p1.ypos + p2.ypos;
    return *pptr;
}