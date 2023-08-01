#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to);
int fib(int n);

int main()
{
    int scores[] = { 6, 3, 2, 1, 3, 4, 5, 7, 1, 0, 9, 3, 5, 1, 8, 1, 2, 3, 9 ,3, 8 };
    int size = sizeof(scores) / sizeof(scores[0]);
    int result = 0;
    hanoi_tower(4, 'A', 'B', 'C');
    for (int i = 0; i < 10; i++)
    {
        result = fib(i);
        printf("fib(%d) = %d\n", i, result);
    }
    printf("%d", size);
}

void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n == 1)
        printf("판 1을 %c에서 %c으로 옮긴다.\n", from, to);
    else
    {
        hanoi_tower(n-1, from, to, tmp); // 먼저 tmp로 원판을 옮기고
        printf("판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to); // tmp에서 to로 원판을 옮긴다
    }
}

int fib(int n)
{
    if (n == 1)
        return 1;
    else if (n == 0)
        return 0;
    else
        return fib(n - 1) + fib(n - 2);
}

void print_array(int a[]) { // a[] 처럼 배열을 넘겨주면 원본이 전달 됨 int앞에 const가 있으면 수정 불가

}