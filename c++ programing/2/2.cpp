#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath> // c의 math.h를 .h를 빼고 c를 붙임으로써 가져와 사용 가능 but 가급적 c++표준헤더 사용하기

using std::cout;
using std::cin;
using std::endl;

int& RefReFuncOne(int& ref);
int RefReFuncTwo(int &ref);
char* MakeStrAdr(int len);

int main()
{
    // 참조자는 변수에 대해서만 선언 가능 아래의 경우 전부 불가
    //int& ref = 20;
    //int& ref;
    //int& ref = NULL;
    int arr[3] = { 1, 3, 5 };
    int& ref1 = arr[0];
    int& ref2 = arr[1];
    int& ref3 = arr[2];
    cout << ref1 << " " << ref2 << " " << ref3 << endl;
    std::cout << "Hello World!\n";

    int num1 = 1;
    int num2 = RefReFuncOne(num1);
    int &num3 = RefReFuncOne(num1);
    int num4 = RefReFuncTwo(num1);
    // int &num5 = RefReFuncTwo(num1); 반환형와 &num5 가 맞지 않음
    cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;

    const int num = 20;
    //int& ref = num; 는 불가 상수는 변경 불가
    const int& ref = num; // 참조 시 const 붙여줘야 함 또한 이 형태는 상수도 참조 가능(임시변수를 만들어 참조가능하게 함)
    
    char* str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    delete []str; // free(str); 대신 사용
    return 0;
}

int& RefReFuncOne(int& ref)
{
    ref++;
    return ref;
}
int RefReFuncTwo(int &ref)
{
    ref++;
    return ref;
}

char* MakeStrAdr(int len)
{
    // char* str = (char*)malloc(sizeof(char) * len); // 힙에 메모리 할당, 길이에 해당하는 배열 생성
    char* str = new char[len]; // 동적할당의 불편함 해소하기 위해 new 사용
    return str;
}