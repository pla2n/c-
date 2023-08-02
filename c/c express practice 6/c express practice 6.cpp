// c express practice 6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S_SIZE 50

typedef struct NODE {
    char title[S_SIZE];
    int year;
    struct NODE* link; // 자기 자신을 노드로써 연결함
} NODE;

struct Book {
    int number;
    char title[50];
};

int main()
{
    int* p;
    p = (int*)malloc(100 * sizeof(int)); // p는 100개의 정수 저장 가능
    struct Book* q;
    q = (struct Book*)malloc(2 * sizeof(struct Book));
    int* z;
    z = (int*)calloc(5, sizeof(int)); // 0으로 초기화된 동적 메모리 할당
    //p = realloc(p, 120 * sizeof(int)); // p만큼 데이터를 받고, 나머지는 malloc처럼 쓰레기값 넣어줌
    free(p); // p의 동적 메모리 반납
    free(q);
    free(z);

    NODE* list = NULL; // 노드를 가르키는 포인터 정의
    NODE* prev, * f, * next;
    char buffer[S_SIZE];
    int year;

    while (1)
    {
        printf("책의 제목을 입력하시오: (종료하려면 엔터)");
        gets_s(buffer, S_SIZE);
        if (buffer[0] == "\0")
            break;
        f = (NODE*)malloc(sizeof(NODE)); // 동적 메모리 할당
        strcpy(f->title, buffer);
        printf("책의 출판 년도를 입력하시오: ");
        gets_s(buffer, S_SIZE);
        year = atoi(buffer);
        f->year = year;

        if (list == NULL) // 기존 연결 리스트의 끝에 새로운 노드를 추가
            list = f;
        else
            prev->link = f;
        f->link = NULL;
        prev = f;
    }
    printf("\n");
    f = list;
    while (f != NULL) // 연결 리스트 안의 노드 순회
    {
        printf("[%s,%d->", f->title, f->year);
        f = f->link;
    }
    printf("\n");
    f = list;
    while (f != NULL)
    {
        next = f->link;
        free(f); // 동적 메모리 반납
        f = next;
    }
    return 0;
}