#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int choice;
    while (true)
    {
        cout << "-----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << "선택: " << endl;
        cin >> choice;
    }
}