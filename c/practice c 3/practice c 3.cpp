#include <stdio.h>
#include <stdlib.h>

void print_binary(int x)
{
    if (x > 0)
    {
        print_binary(x / 2);
        printf("%d", x % 2); // 출력을 나중에 해야 2진수가 제대로 출력됨
    }
}

int get_int(int* px, int* py)
{
    return *px + *py;
}

void def(int x[], int *y); // 배열을 포인터로 넘기든 배열로 넘기든 둘은 같은 방법임

int main()
{
    int* p = (int*)10000; // 포인터 초기화, *p는 p가 가르키는 위치에 있는 데이터를 가져오라는 의미 
    char c = 'A';
    char* pci = &c; // *는 간접 참조, &는 주소를 포인터에 대입하는 대입 연산자(주소를 읽어옴)
    for (int i = 0; i < 10; i++) {
        static int a = 0; // 다시 호출되어도 초기화 되지 않음, extern으로 연결 불가
        auto c = 1; // 블록을 벗어나면 데이터 삭제, 권장 사용법
        int b = 0; // 블록을 벗어나도 데이터는 유지
        register int d = 2; // cpu에 제한된 레지스터 사용, 주소 사용 불가, 블록 벗어나면 삭제, 자주 쓰는 변수에 사용
        printf("%d ", a++);
        printf("%d ", c++);
        printf("%d ", d++);
        printf("%d\n", b++);
    }
    extern int e; // 다른 소스코드에서 정의된 변수 가져오기, 저장공간 할당 x, static과 같이 함수에 사용 가능
    int i = 3000;
    int* pin = NULL; // 포인터의 값을 초기화 시키지 않는 것은 매우 큰 문제가 발생 가능
    pin = &i; // 0으로 정의된 NULL이 차라리 나음
    //int *p8 = 10000; 이렇게 p8의 주소를 정해주는데, 이런 식의 절대 주소 사용 자제(어떤 용도인지 모름)
    printf("%d\n", *pin);
    printf("%d\n", pin);
    *pin = 2200; // 포인터의 값 변경시
    printf("%d\n", *pin);
    printf("%d\n", pin);

    char* pc;
    int* pi;
    double* pd;
    pc = (char*)10000;
    pi = (int*)10000;
    pd = (double*)10000;
    printf("증가 전 %d %d %d \n", pc, pi, pd);
    pc++;
    pi++;
    pd++;
    printf("증가 후 %d %d %d \n", pc, pi, pd); // 자료형의 크기에 따라 증가되는 값이 다름

    int v = 10;
    int* pz=&v;
    v = *pz++; // p가 가리키는 값을 v에 대입한 후에 p 증가
    v = (*pz)++; // p가 가리키는 값을 v에 대입 후 p가 가리키는 값 증가
    v = *++pz; // p를 증가시킨 후에 p가 가르키는 값을 v에 대입
    v = ++ * pz; // p가 가리키는 값을 가져온 후에 그 값을 증가하여 v에 대입

    double* pdd;
    int* pii;
    const int* l; // 포인터가 const로 선언되면 매개변수 (l)을 통해 값 변경 불가
    // pii = (int*)pdd; // 형변환 연산자를 앞에 써줌으로써 포인터의 형변환 가능


    // 함수 안의 지역변수는 포인터로 반환하면 안됨 (함수가 종료되면 사라지기 때문에)
    int z[] = { 10, 20, 30, 40, 50 };
    printf("%u\n", &z[0]);
    printf("%u\n", &z[1]); // 포인터의 주소는 배열의 첫 요소가 반환됨

    printf("%u\n", z);
    printf("%u\n", z+1);
    printf("%u\n", *z);
    printf("%u\n", *(z+1));
    int x = 10;
    int y = 20;
    int result;
    result = get_int(&x, &y);
    printf("%d", result);
    return 0;
}

// 유용한 함수들
// getchar(), _getch(), _getche, puts, gets_s, isalpha, isupper, islower, isdigit, isalnum, isxdigit
// isspace, ispunct, isprint, iscntrl, isascii, toupper, tolower, toascii
// strlen, strcpy, strcat, strcmp, strncpy, strncat, strncmp, strchr, strstr, *strtok
// sscanf, sprintf