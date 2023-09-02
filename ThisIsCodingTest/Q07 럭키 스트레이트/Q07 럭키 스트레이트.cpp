#include <iostream>
using namespace std;

int main()
{
    string n;
    int a, frontint=0, lastint=0;
    cin >> n;
    for (int i = 0; i < n.length() / 2; i++)
        frontint += n[i];
    for (int i = n.length() / 2; i < n.length(); i++)
        lastint += n[i];
    if (frontint == lastint)
        cout << "LUCKY";
    else
        cout << "READY";
    return 0;
}