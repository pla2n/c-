#include <iostream>

int main()
{
    int number;
    std::cout << "구구단을 외자! 숫자 하나를 입력 해 주세요!";
    std::cin >> number;

    for (int i = 1; i < 10; i++)
        std::cout << i * number << std::endl;
}