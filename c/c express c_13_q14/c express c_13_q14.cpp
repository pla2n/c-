#include <stdio.h>
#include <string.h>

enum genre {song, pop, classic, movie};

struct music {
    char name[30];
    char singer[20];
    char location[30];
    enum genre g;
};

int menu(int a);
void add(struct music *m);
void printout(struct music m[], int count);
void search(struct music m[], int count);
int quit(int q);

int main()
{
    int a = 0, count = 0, q = 1;
    struct music m[100];
    while (1)
    {
        a = menu(a);
        switch (a)
        {
        case 1:
            add(&m[count]);
            count++;
            break;
        case 2:
            for (int i = 0; i < count; i++)
                printout(m, i);
            break;
        case 3:
            search(m, count);
            break;
        case 4:
            q = quit(q);
            break;
        default:
            break;
        }
        if (q == 0)
            break;
    }
    return 0;
}

int menu(int a)
{
    printf("============================\n 1. 추가\n 2. 출력\n 3. 검색\n 4. 종료\n");
    printf("============================\n");
    printf("정수값을 입력하시오 :");
    scanf(" %d", &a);
    return a;
}
void add(struct music *m)
{
    printf("제목:");
    scanf(" %[^\n]", m->name);
    printf("가수:");
    scanf(" %[^\n]", m->singer);
    printf("위치:");
    scanf(" %[^\n]", m->location);
    printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악):");
    scanf(" %d", &m->g);
}

void printout(struct music m[], int count)
{
    printf("노래 제목:%s\n", m[count].name);
    printf("가수 이름:%s\n", m[count].singer);
    printf("위치:%s\n", m[count].location);
    switch (m[count].g)
    {
    case song:
        printf("장르: 가요");
        break;
    case pop:
        printf("장르: 팝");
        break;
    case classic:
        printf("장르: 클래식");
        break;
    case movie:
        printf("장르: 영화 음악");
        break;
    }
}
void search(struct music m[], int count)
{
    char c[30];
    int found = 0;
    printf("검색 할 노래 제목을 입력 해 주세요:");
    scanf(" %[^\n]", c);
    for (int i = 0; i < count; i++) {
        if (strcmp(m[i].name, c)==0) {
            printout(m, i);
            found += 1;
            break;
        }
    }
    if (found == 0)
        printf("검색하신 노래를 찾을 수 없습니다.\n");
}

int quit(int q)
{
    return 0;
}