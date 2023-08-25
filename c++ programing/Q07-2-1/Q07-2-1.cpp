#include <iostream>
using std::cout;
using std::endl;

class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(int width, int height) : width(width), height(height)
    {}
    void ShowAreaInfo()
    {
        cout << "면적: " << width * height << endl;
    }
    ~Rectangle()
    {}
};

class Square : public Rectangle
{
private:
    int side;
public:
    Square(int side) : Rectangle(side, side)
    {}
    ~Square()
    {}
};
int main()
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}