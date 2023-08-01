#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    int a = 3, b = 4;

    printf("%d", (a > b) ? a : b);

    printf("윤년 판별기:");
    scanf("%d", &a);

    if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {
        printf("윤년입니다.\n");
    }
    else
        printf("윤년이 아닙니다\n");

    char a1, a2, a3, a4; // 변수를 비트를 나눠 저장하는 법
    unsigned int b1 = 0;
    printf("first:");
    scanf(" %c", &a1);
    printf("second:");
    scanf(" %c", &a2);
    printf("third:");
    scanf(" %c", &a3);
    printf("fourth:");
    scanf(" %c", &a4);
    b1 |= a1 << 0;
    b1 |= a2 << 8;
    b1 |= a3 << 16;
    b1 |= a4 << 24;
    printf("Combined value: %x\n", b1);

    switch (b1)
    {
        case 0:
            printf("0\n");
            break; // break가 없으면 다음 case도 계속해서 검사함
        case 1:
            printf("1\n");
            break;
        default:
            printf("없음\n");
            break;
    }
    if (b1 == 0) // switch문은 if-else 문으로도 표현 가능 (선택해야 할 경우의 수가 많다면 switch 사용)
        printf("0\n");
    else if (b1 == 1)
        printf("1\n");
    else
        printf("없음\n");

    int n=0;
    do // 문장을 적어도 한 번은 실행
    {
        n++;
    } while (n<10);

    for (int i = 0; i < 10; i++) {
        printf("1");
    }

    printf("\n%d\n", 1+(rand() % 45)); // 1을 더함으로써 1~45까지의 랜덤 정수
    srand((unsigned)time(NULL)); // time값을 넣어줌으로싸 난수가 시간에 따라 랜덤 생성됨
    printf("\n%d\n", 1 + (rand() % 45));


    HDC hdc = GetWindowDC(GetForegroundWindow());
    int i;
    for (i = 0; i < 100; i++) {
        int x = rand() % 500;
        int y = rand() % 300;
        int w = rand() % 100;
        int h = rand() % 100;
        Rectangle(hdc, x, y, x + w, y + h);
        Sleep(100);
    }
    return 0;
    // char choice, choice = getchar()
}