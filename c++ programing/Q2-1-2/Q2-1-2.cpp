#include <iostream>

void SwapPointer(int& a, int& b);

int main()
{
    int num1 = 5;
    int* ptr1 = &num1;
    int num2 = 10;
    int* ptr2 = &num2;
    SwapPointer(*ptr1, *ptr2);
    std::cout << *ptr1 << " " << *ptr2 << std::endl;
}

void SwapPointer(int& a, int& b)
{
    int tmp = a; // 굳이 포인터로 지정해주지 않아도 괜찮음
    a = b;
    b = tmp;
}