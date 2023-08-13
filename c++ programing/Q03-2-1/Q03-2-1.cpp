#include <iostream>
using std::cout;
using std::endl;

class Calculator
{
private:
    int add, min, mul, div;
public:
    void Init();
    double Add(double x, double y);
    double Min(double x, double y);
    double Mul(double x, double y);
    double Div(double x, double y);
    void ShowOPCount();
};

void Calculator::Init()
{
    add = 0, min = 0, mul = 0, div = 0;
}

double Calculator::Add(double x, double y)
{
    add += 1;
    return x + y;
}
double Calculator::Min(double x, double y)
{
    min += 1;
    return x - y;
}
double Calculator::Mul(double x, double y)
{
    mul += 1;
    return x * y;
}
double Calculator::Div(double x, double y)
{
    div += 1;
    return x / y;
}
void Calculator::ShowOPCount()
{
    cout << "덧셈: " << add << " 뺄셈: " << min << " 곱셈: " << mul << " 나눗셈: " << div << endl;
}

int main()
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 =" << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 + 1.7 =" << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 + 2.4 =" << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 + 2.4 =" << cal.Div(4.9, 1.2) << endl;
    cal.ShowOPCount();
    return 0;
}