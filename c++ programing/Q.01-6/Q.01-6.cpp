#include <iostream>
using std::cout;
using std::cin;
using std::endl;


void menu();
void makeAcc();
void deposit();
void withdraw();
void printall();
void quit();

typedef struct
{
    int AccID;
    char name[20];
    int balance;
} Account;

Account acc[100];
int count = 0;

int main()
{
    int choice;
    while (true)
    {
        menu();
        cout << "선택: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            makeAcc();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            printall();
            break;
        case 5:
            return 0;
        }
    }
}

void menu()
{
    cout << endl;
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void makeAcc()
{
    cout << endl;
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> acc[count].AccID;
    cout << "이름: ";
    cin >> acc[count].name;
    cout << "입금액: ";
    cin >> acc[count].balance;
    count++;
}
void deposit()
{
    int id, deposit;
    cout << endl;
    cout << "[입  금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> deposit;

    for (int i = 0; i < count; i++) {
        if (acc[i].AccID == id) {
            acc[i].balance += deposit;
            cout << "입금완료" << endl;
            return;
        }
    }
    cout << "일치하는 ID가 없습니다." << endl;
}
void withdraw()
{
    int id, withdraw;
    cout << endl;
    cout << "[출  금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> withdraw;

    for (int i = 0; i < count; i++) {
        if (acc[i].AccID == id) {
            if (acc[i].balance >= withdraw) {
                acc[i].balance -= withdraw;
                cout << "출금완료" << endl;
                return;
            }
            else {
                cout << "잔액부족" << endl;
                return;
            }
        }
    }
    cout << "일치하는 ID가 없습니다." << endl;
}
void printall()
{
    for (int i = 0; i < count; i++) {
        cout << endl;
        cout << "계좌ID: " << acc[i].AccID << endl;
        cout << "이름: " << acc[i].name << endl;
        cout << "잔액: " << acc[i].balance << endl;
    }
}