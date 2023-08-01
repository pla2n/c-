#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h> // _getch();

int main()
{
    int i, x, y, red, green, blue;
    double result, value = 1.6;

    result = floor(value); // 반 내림
    printf("%lf ", result);
    result = ceil(value); // 반 올림
    printf("%lf ", result);
    printf("%f", fabs(-12)); // 절대값
    printf("%0.f", pow(10.0, 3.0)); // 제곱
    printf("%.0f", sqrt(16)); // 제곱근
    // sin, cos, tan(double x)
    system("dir"); // 명령어 실행
    _getch(); // 문자 하나 입력 받음
    system("cls");
    HDC hdc;
    hdc = GetWindowDC(GetForegroundWindow());

    srand((unsigned)time(NULL));
    for (i = 0; i < 1000; i++)
    {
        x = rand() % 300;
        y = rand() % 300;

        red = rand() % 256;
        green = rand() % 256;
        blue = rand() % 256;

        SetPixel(hdc, x, y, RGB(red, green, blue));
    }
    //_getch(); // 사용자가 입력하는 하나의 문자를 받음
    return 0;
}