#include <iostream>

using std::cout;
using std::endl;

class Printer
{
private:
    char print[50];
public:
    void SetString(const char* s);
    void ShowString();
};

void Printer::SetString(const char* s)
{
    strcpy(print, s);
}

void Printer::ShowString()
{
    cout << print << endl;
}

int main()
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();
    
    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}