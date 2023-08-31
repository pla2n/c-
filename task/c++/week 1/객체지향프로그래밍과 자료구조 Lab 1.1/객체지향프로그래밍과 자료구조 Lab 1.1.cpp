/**
* 파일명: "객체지향프로그래밍과자료구조 Homework 1.2.cpp"
* 프로그램의 목적 및 기본 기능:
*- 이 프로그램은 배열 동적 생성을 통해 NUM_RANDS 크기의 배열을 만들고,
*  genBigRandArray에서 함수에 주어진 offset ~ NUM_RANDS + offset 범위의 정수를 배열에 넣어주고,
*  shuffling 기능을 하는 반복문을 통해 배열을 한 번 shuffle 해준다.
*
* 프로그램 작성자: 이세용 (2023년 8월 30일),
* 최종 수정 및 보완 : Version 1.0, 2023년 8월 30일 (이세용).
*
* =========================================================================================
* 프로그램 수정/보완 이력
* =========================================================================================
* 프로그램 수정/ 보완작업자      일자      수정/보완 내용
* 이세용           2023/08/30    v1.0
*
*
* =========================================================================================
*/


#include <iostream>
#include <algorithm>
#define NUM_RANDS 10000000 // 난수의 범위, 배열의 크기를 결정해 줌
int* genBigRandArray(int num_rands, int offset);

int main()
{
	int* array;
	array = (int*)calloc(NUM_RANDS, sizeof(int)); // genBigRandArray 한 return을 받기위해 배열을 동적생성 해줌
	array = genBigRandArray(NUM_RANDS, 5); // 함수 호출

	// 배열이 정상적으로 생성되었는지 확인하기위해 최대값을 확인하기 위해 만듬
	/*int max_value = INT_MIN; 
	for (int i = 1; i < NUM_RANDS; ++i) {
		if (array[i] > max_value) {
			max_value = array[i];
		}
	}
	std::cout << max_value;*/
	return 0;
}

int* genBigRandArray(int num_rands, int offset)
{
	srand(time(0));
	int* pBigRandArray;
	int tmp;
	long idx;
	pBigRandArray = (int*)calloc(num_rands, sizeof(int)); // num_rands만큼 int형으로 동적할당
	for (int i = 0; i < num_rands; i++)
		pBigRandArray[i] = i + offset; // offset ~ num_rands+offset범위의 정수를 차례대로 pBigRandArray에 넣어줌

	for (int i = 0; i < num_rands; i++) { // shuffling
		idx = (((long)rand() << 15) | rand()) % num_rands; // long을 사용해 int형보다 큰 숫자를 담을 수 있게 해주고,
		// << 15 를 통해 rand()로 나온 값을 2^15을 곱한 값으로 만들어 줌 (비트 연산을 통해 더 큰 범위의 난수를 만듬)
		// % num_rands를 통해 idx값을 0~ num_rands-1 사이의 값으로 한정함
		if (i == idx) // 임의의 난수와 현재 위치가 같기 때문에 shuffling 할 이유가 없음
			continue;
		else { // i의 위치의 값과 idx 위치의 값을 서로 바꿔줌
			tmp = pBigRandArray[i];
			pBigRandArray[i] = pBigRandArray[idx];
			pBigRandArray[idx] = tmp;
		}
	}
	return pBigRandArray;
}