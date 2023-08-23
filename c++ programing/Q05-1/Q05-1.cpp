#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowPosition(int pos)
    {
        switch (pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
        }
    }
}
class NameCard
{
private:
    char* name;
    char* company;
    char* number;
    int pos;
public:
    NameCard(const char* name, const char* company, const char* number, int pos) : pos(pos)
    { // 처음 변수 초기화를 const로 받았기 때문에 const 사용
        this->name = new char[strlen(name) + 1];
        this->company = new char[strlen(company) + 1];
        this->number = new char[strlen(number) + 1];
        strcpy(this->name, name);
        strcpy(this->company, company);
        strcpy(this->number, number);
    }

    NameCard(const NameCard& copy) : pos(copy.pos)
    {
        name = new char[strlen(copy.name) + 1];
        company = new char[strlen(copy.name) + 1];
        number = new char[strlen(copy.name) + 1];
        strcpy(name, name);
        strcpy(company, company);
        strcpy(number, number);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << number << endl;
        cout << "직급: ";
        COMP_POS::ShowPosition(pos);
        cout << endl;
    }
    ~NameCard()
    {
        delete[] name;
        delete[] company;
        delete[] number;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}