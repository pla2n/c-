#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main()
{
    string n, letter, number;

    cin >> n;
    for (char c : n) {
        if (isDigit(c)) {
            number += c;
        }
        else {
            letter += c;
        }
    }
    sort(number.begin(), number.end());
    sort(letter.begin(), letter.end());
    cout << letter << number;
}