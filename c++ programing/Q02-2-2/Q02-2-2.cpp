#include <iostream>
using std::cout;
using std::endl;
int main()
{
    const int num = 12;
    const int* a = &num;
    const int& b = *a;
    cout <<"a: "<< *a << endl << "b: " << b << endl;
}
