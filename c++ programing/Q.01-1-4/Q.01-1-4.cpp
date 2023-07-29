#include <iostream>

int main()
{
    int pay;
    while (true)
    {
        std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin >> pay;
        if (pay == -1)
            break;
        std::cout << "이번 달 급여: " << ((pay*3)/25) + 50 << "만원\n";
    }
}