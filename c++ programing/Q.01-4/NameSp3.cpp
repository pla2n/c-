#include "NameSp2.h"

void BestComImpl::SimpleFunc(void) // 이름 공간에 따라 같은 함수를 나눔
{
    std::cout << "BestCom 정의 함수" << std::endl;
}
void ProgComImpl::SimpleFunc(void)
{
    std::cout << "ProgCom 정의 함수" << std::endl;
}