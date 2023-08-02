#include <stdio.h>
#include "power.h" // 헤더파일에는 함수 원형, 구조체 정의, 매크로 정의, typedef의 정의를 넣어줌
#define SQUARE(x) ((x)*(x)) // 괄호로 묶어주는게 안전함 매개변수도 다 묶어줌
#define PRINT(exp) printf("exp=%d\n", exp)
#define ASSERT(exp) { if !(exp) \
{ printf("가정(" #exp ")이 소스파일 %s %d번째 줄에서 실패.\n"\,__FILE__, __LINE__), exit(1);}}
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define GET_BIT(w, k) (((w) >> (k)) & 0x01)

struct product { // 비트 필드 구조체
    unsigned style : 3; // 3비트
    unsigned size : 2; // 2비트
    unsigned color : 1; // 1비트
    unsigned : 2; // 자리만 차지하는 2비트(워드의 경계에 비트필드가 걸치면 입출력 속도가 느려짐)
};

int main(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++)
        printf("명령어 행에서 %d번째 문자열 = %s\n", i, argv[i]); // argv[0]은 무조건 프로그램명
    return 0;
    FILE* fp;
    fp = fopen("test.txt", "w"); // r, w, a, r+, w+, a+, t, b
    fclose(fp); // fopen을 해줬으면 반드시 파일을 닫아줘야 함
    // 파일 입출력에 대한 자세한 내용은 책 보고 다시 공부하기
    int sum = 100;
    unsigned gender : 3; // 3개의 비트로 구성된 gender생성


    ASSERT(sum == 0);
#ifdef DEBUG // DEBUG가 정의되어 있따면 #ifdef 부터 #endif 까지 모두 다 실행, #else도 사용 가능
    printf("");
#endif
#ifndef LIMIT // 정의 되어 있지 않다면 정의
#define LIMIT 1000
#undef LIMIT // 정의 취소
#endif
#if DEBUG == 1
    printf("");
#endif
    return 0;
}
