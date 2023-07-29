#include "NameSp2.h"
/*using namespace std;*/ // 사용 시 이제부터 모든 std 생략 가능하지만 생략하는 범위가 넓어서
using std::cin; // 오류날 확률도 커짐 그래서 3, 4, 5행처럼 일일이 다 제거해 주는게 좋음
using std::cout;
using std::endl;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int val = 100;
int main()
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    namespace ABC = AAA::BBB::CCC; // 이름공간이 여러개 호출 되어 있을 때, 이런 식으로 압축해줄 수 있음
    ABC::num1 = 20;
    ABC::num2 = 30;
    cout << ABC::num1 << endl;
    cout << ABC::num2 << endl;
    int val = 20;
    cout << val << endl;
    cout << ::val << endl; // 전역 변수 호출

    return 0;
}