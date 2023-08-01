#include <stdio.h>
#include <string.h>

void secure(char m[], int shift);

int main()
{
    char m[50];
    int shift = 3;
    printf("문자열을 입력하세요:");
    gets_s(m, 50);
    printf("%s", m);
    secure(m, shift);
    printf("%s", m);
    return 0;
}

void secure(char m[], int shift)
{
    for (int i = 0; i < strlen(m); i++)
    {
        if ('a' <= m[i] && m[i] <= 'z') {
            m[i] += shift;
            if (m[i] > 'z') // shift값을 m에 더했을 때, 소문자의 범위를 넘어서게 된다면 소문자로 돌아가게 해줌
                m[i] -= 26;
        }
    }
}