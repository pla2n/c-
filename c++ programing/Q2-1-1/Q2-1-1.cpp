#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void add(int &a);
void reverse(int& a);

int main()
{
	int a = -30;
	cout << a << endl;
	add(a);
	cout << a << endl;
	reverse(a);
	cout << a << endl;
}

void add(int& a)
{
	a++;
}
void reverse(int& a)
{
	a = -a;
}