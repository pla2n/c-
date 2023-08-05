#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    /*strlen();
    strcat();
    strcpy();
    strcmp();*/
    srand(time(0));
    int A = rand() % 100 + 1;
    cout << A;

}