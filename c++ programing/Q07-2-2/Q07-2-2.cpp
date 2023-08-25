#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* name, const char* number, int price) : price(price)
    {
        title = new char[strlen(name) + 1];
        strcpy(title, name);
        isbn = new char[strlen(number) + 1];
        strcpy(isbn, number);
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
};

class EBook : public Book
{
private:
    char* DRMKey;
public:
    EBook(const char* name, const char* number, int price, const char* secure)
        : Book(name, number, price)
    {
        DRMKey = new char[strlen(secure) + 1];
        strcpy(DRMKey, secure);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
};
int main()
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}