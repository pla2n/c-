#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(const char* name, int age) : age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~MyFriendInfo()
    {
        delete[] name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone) : MyFriendInfo(name, age)
    {
        this->addr = new char[strlen(addr) + 1];
        strcpy(this->addr, addr);
        this->phone = new char[strlen(addr) + 1];
        strcpy(this->phone, phone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << " 전화: " << phone << endl << endl;
    }
    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    } 
};
int main()
{
    MyFriendDetailInfo a("Kim", 23, "Oksanro 105", "010-1234-5678");
    a.ShowMyFriendDetailInfo();
}