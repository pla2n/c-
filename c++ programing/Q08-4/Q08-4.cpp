#include <iostream>
#include <cstring>

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};
const int NAME_LEN = 20;

using std::cout;
using std::cin;
using std::endl;

class Account
{
private:
    int AccID;
    char* name;
    int balance;
public:
    Account(int AccID, char* name, int balance) :AccID(AccID), balance(balance)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Account(const Account& ref) : AccID(ref.AccID), balance(ref.balance)
    {
        name = new char[strlen(ref.name) + 1];
        strcpy(name, ref.name);
    }
    int getbalance() const { return balance; }

    int getID() const { return AccID; }
    void deposit(int money) {
        balance += money;
    }
    void withdraw(int money) {
        if (balance > money) {
            balance -= money;
            cout << "출금완료" << endl;
        }
        else
            cout << "잔액부족" << endl;
    }

    void showinfo() const {
        cout << endl;
        cout << "계좌ID: " << AccID << endl;
        cout << "이름: " << name << endl;
        cout << "잔액: " << balance << endl;
    }

    ~Account()
    {
        delete[]name;
    }
};

class NormalAccount: public Account
{
private:
    int interest;
public:
    NormalAccount(int id, char* name, int balance, int interset) : Account(id, name, balance), interest(interset)
    {}
    virtual void deposit(int money)
    {
        Account::deposit(money);
        Account::deposit(money * (interest / 100));
    }
};

class HighCreditAccount: public NormalAccount
{
private:
    int grade;
public:
    HighCreditAccount(int id, char* name, int balance, int interest, int grade) : NormalAccount(id, name, balance, interest)
        , grade(grade)
    { }
    virtual void deposit(int money)
    {
        NormalAccount::deposit(money);
        Account::deposit(money * (grade / 100));
    }
};

class AccountHandler
{
private:
    Account* acc[100];
    int count;
public:
    AccountHandler() : count(0)
    {}
    void menu()
    {
        cout << "-----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;
    }

    void makeAcc()
    {
        int choice;
        cout << "[계좌종류선택]" << endl;
        cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
        cout << "선택: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "[보통예금계좌 개설]" << endl;
            MakeNormalAccount();
            break;
        case 2:
            cout << "[신용예금계좌 개설]" << endl;
            MakeHighCreditAccount();
            break;
        }
    }

    void MakeNormalAccount()
    {
        int id, balance, interest;
        char name[NAME_LEN];
        cout << "계좌ID: ";
        cin >> id;
        cout << "이름: ";
        cin >> name;
        cout << "입금액: ";
        cin >> balance;
        cout << "이자율: " << endl;
        cin >> interest;
        acc[count++] = new NormalAccount(id, name, balance, interest);
    }

    void MakeHighCreditAccount()
    {
        int id, balance, interest, grade;
        char name[NAME_LEN];
        cout << "계좌ID: ";
        cin >> id;
        cout << "이름: ";
        cin >> name;
        cout << "입금액: ";
        cin >> balance;
        cout << "이자율: ";
        cin >> interest;
        cout << "신용등급(1toA, 2toB, 3toC):" << endl;
        cin >> grade;
        switch (grade)
        {
        case 1:
            acc[count++] = new HighCreditAccount(id, name, balance, interest, LEVEL_A);
        case 2:
            acc[count++] = new HighCreditAccount(id, name, balance, interest, LEVEL_B);
        case 3:
            acc[count++] = new HighCreditAccount(id, name, balance, interest, LEVEL_C);
        }
    }

    void deposit()
    {
        int id, deposit;
        cout << "[입  금]" << endl;
        cout << "계좌ID: ";
        cin >> id;
        cout << "입금액: ";
        cin >> deposit;

        for (int i = 0; i < count; i++) {
            if (acc[i]->getID() == id) {
                acc[i]->deposit(deposit);
                cout << "입금완료" << endl;
                return;
            }
        }
        cout << "일치하는 ID가 없습니다." << endl;
    }
    void withdraw()
    {
        int id, withdraw;
        cout << "[출  금]" << endl;
        cout << "계좌ID: ";
        cin >> id;
        cout << "출금액: ";
        cin >> withdraw;

        for (int i = 0; i < count; i++) {
            if (acc[i]->getID() == id) {
                acc[i]->withdraw(withdraw);
                return;
            }
        }
        cout << "일치하는 ID가 없습니다." << endl;
    }
    void printall()
    {
        for (int i = 0; i < count; i++)
            acc[i]->showinfo();
    }
    ~AccountHandler()
    {
        for (int i = 0; i < count; i++)
            delete acc[i];
    }
};

int main()
{
    AccountHandler manager;
    int choice;
    while (1)
    {
        manager.menu();
        cout << "선택: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case MAKE:
            manager.makeAcc();
            break;
        case DEPOSIT:
            manager.deposit();
            break;
        case WITHDRAW:
            manager.withdraw();
            break;
        case INQUIRE:
            manager.printall();
            break;
        case EXIT:
            return 0;
        default:
            cout << "No you can't" << endl;
        }
    }
}