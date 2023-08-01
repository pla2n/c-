#include <stdio.h>

void menu() {
    printf("=========================================\nMENU\n");
    printf("=========================================\n");
    printf("1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n5. 나머지\n");
}
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int div(int x, int y) {
    return x / y;
}

int remainder(int x, int y) {
    return x % y;
}

char repeat(int result) {
    char ch;
    printf("연산결과 :%d\n", result);
    printf("계속 하려면 y를 누르시오:");
    getchar();
    scanf(" %c", &ch);
    return ch;
}

int main()
{
    int choice, a, b, result = 0;
    char con = 'y';

    while (con == 'y') {
        printf("원하는 메뉴를 선택하시오(1~5):");
        scanf("%d", &choice);
        printf("숫자 2개를 입력하시오:");
        scanf("%d %d", &a, &b);
        if (b > a) {
            int N;
            N = b;
            b = a;
            a = N;
        }

        getchar();

        switch (choice)
        {
        case 1:
            result = add(a, b);
            break;
        case 2:
            result = sub(a, b);
            break;
        case 3:
            result = mul(a, b);
            break;
        case 4:
            result = div(a, b);
            break;
        case 5:
            result = remainder(a, b);
            break;
        }
        con = repeat(result);
    }
    return 0;
}