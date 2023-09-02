#include <windows.h> // Performance counter 활용 위해 필요한 라이브러리
#include <iostream>

int main()
{
	LARGE_INTEGER timer, start, end; // 부호가 있는 64비트 정수형 데이터를 저장하기 위해 선언된 사용자 정의 자료형(QuardPart LowPart 하위 32비트 DWORD형, HighPart 상위 32비트 LONG형 둘다 사용해 큰값 사용, 고해상도 값 활용)
	float Time;
	int count = 0;
	QueryPerformanceCounter(&timer); // Performance counter의 frequency를 QuardPart 멤버변수에 저장

	QueryPerformanceCounter(&start); // 시작 지점의 cpu 클럭 수를 start를 QuardPart 멤버변수에 저장

	for (int i = 0; i < 100000000; i++) // 실행할 코드
		count += 1;

	QueryPerformanceCounter(&end); // 종료 지점의 cpu 클럭 수를 end에 저장

	Time = (end.QuadPart - start.QuadPart) / (float)timer.QuadPart; // QuardPart는 LARGE_INTEGER 구조체의 멤버 변수, 64비트 정수형 값.
	std::cout << Time;
	return 0;
}