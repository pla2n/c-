#include <stdio.h>

enum days { SUN=7, MON=1, TUE, WED, THU, FRI, SAT }; // 열거형 정의, 값을 정의해줄 수 있음

struct date {
    int year;
    int month;
    int day;
};
struct student {
    int number;
    char name[10];
    double grade;
    struct date dob; // 이중 구조체 가능 s.dob.year 와 같은 식으로 호출
    char* p;
    union { // 구조체 안 공용체
        int stu_number;
        char reg_number[15];
    } id; // 이름은 뒤에 선언
};

union example { // 공용체
    int i; // 멤버 변수 i와 c가 같은 공간을 공유한다
    char c;
};

int equal(struct student* p1, struct student* p2); // 포인터로 구조체를 받을 경우. *을 붙이지 않으면 구조체가 복사됨

typedef struct point { // typedef는 #define과 비슷하지만, 컴파일러가 직접 처리하기 때문에 권장
    int x; // 이식성이 좋고(바이트등 지정 가능), 문서화의 역할 가능(주석처럼 사용 가능)
    int y;
} POINT; // typedef로 구조체 정의

int main()
{
    struct student s;
    struct student list[100]; // 구조체 100개 저장 가능
    struct student* p;
    union example v;
    enum days today;
    typedef int INT32;
    today = SUN; // today는 7의 값으로도 사용 가능, 열거형의 경우 위에서 정의된 값들만 가질 수 있음
    scanf("%d", &s.number);
    scanf("%s", s.name); // name은 이미 배열임
    scanf("%lf", &s.grade);
    p = &s;
    printf("학번=%d 이름=%s 학점=%f \n", s.number, s.name, s.grade); // 이 세 문장은 같은 문장임
    printf("학번=%d 이름=%s 학점=%f \n", (*p).number, (*p).name, (*p).grade);
    printf("학번=%d 이름=%s 학점=%f \n", p->number, p->name, p->grade);

    scanf("%s", s.p); // 불가. 구조체 포인터는 문자열이 저장된 경우 가르키는것까지만 가능
    //s.p = "강감찬"; // 가능하다는데 왜 안되냐
    equal(&s, &list[0]); // 구조체를 포인터로 보낼경우 &를 붙여줘야 함
    v.c = 'A';
    INT32 i; // int i 와 같음
}