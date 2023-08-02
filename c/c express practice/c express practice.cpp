#include <stdio.h>
#include <math.h>
void set_pointer(char** a) // 이중 포인터 함수로 보내는 법(인데 그대로 따라해도 잘 안되네)
{
    char buffer[] = "All that glisters is not gold";
    *a = buffer;
}

int add(int, int);
int sub(int, int);

double f1(double k);
double f2(double k);
double formula(double (*pf)(double), int n); // 함수 인수로서 함수 포인터 사용 가능

void memzero(void* ptr, size_t len); // void로 포인터를 문자형에 상관없이 받을 수 있음


int main()
{
    int i = 100, result = 0;
    int* p = &i;
    int** q = &p;
    char *a;
    char* z[10]; // 포인터들에 대한 배열이 만들어짐 ([]이 *보다 우선순위가 높음)
    char *fruits[ ] = { // 포인터 배열이 아니면 char fruits[4][10] 이런식으로 크기를 지정해야함
        (char*) "apple", // 포인터들의 배열이 만들어짐
        (char*) "blueberry",
        (char*) "orange",
        (char*) "melon"
    };
    int b[5] = { 1, 2, 3, 4, 5 };
    int(*pa)[5];// int[5] 배열에 대한 포인터 선언, 배열을 가르키는 포인터 선언
    pa = &b; // b를 pa에 넣어줌
    *p = 200;
    set_pointer(&a); // 이런 식으로 주소를 넘겨줘야함 아니면 함수 안에서 값이 바뀌어도 적용 x
    int (*pf)(int, int); // 함수의 포인터, 매개변수를 같게 만들어 줘야함
    int (*pf2[2])(int, int) = { add, sub }; // 함수의 배열의 포인터

    char s[] = "Barking dogs seldom bite.";
    const char* k = s; // k[3] = 'a'로 변경 불가, k = t 로 k는 변경 가능
    char* const q = s; // q[3] = 'a'로 변경 가능, q = t 로 q는 변경 불가능
    volatile char* e; // 다른 프로세스나 스레드가 값을 항상 변경할 수 있으니 값을 사용할 떄마다 다시 메모리에서 읽음
    // 컴파일러의 최적화를 방해하지만, 불시에 변경되는 값을 처리하는 경우에는 불가피하다.

    printf("%d\n", i);
    printf("%s\n", a);
    **q = 300;
    printf("%d\n", i); // 이중 포인터
    printf("%s\n", fruits[0]);
    for (int i = 0; i < 5; i++) {
        printf("%d \n", (*pa)[i]);
    }
    
    pf = add; // 이런 식으로 함수에 대한 포인터 지정 가능
    result = pf(10, 20);
    printf("10+20은 %d\n", result);
    pf = sub; // 이런 식으로 함수에 대한 포인터 지정 가능
    result = pf(10, 20);
    printf("10-20은 %d\n", result);
    result = pf2[0](10, 20);
    printf("10+20은 %d\n", result);
    result = pf2[1](10, 20);
    printf("10-20은 %d\n", result);

    printf("%f\n", formula(f1, 10)); // 함수 인수로 함수 포인터 사용
    printf("%f\n", formula(f2, 10));
}

int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}

double f1(double k)
{
    return 1.0/k;
}
double f2(double k)
{
    return cos(k);
}
double formula(double (*pf)(double), int n)
{
    int i;
    double sum = 0.0;
    
    for (int i = 1; i < n; i++)
        sum += pf(i) * pf(i) + pf(i) + 1;
    return sum;
}

void memzero(void* ptr, size_t len) {
    printf("");
}