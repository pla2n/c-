/**
* 파일명: "main.cpp (Lab01 구조체 struct Student 설계 및 구현)"
* 프로그램의 목적 및 기본 기능:
*- 이 프로그램은 main으로써 헤더파일을 포함해 Student.cpp에서 정의한 함수들을 사용할 수
*  있도록 해주고, 함수들을 적절히 이용해 학생들의 st_id, gpa등과 같은 Student 구조체 요소들을
*  그냥 출력할수도 있고, 선택 정렬해서 출력할 수도 있으며, 원하는 학번을 이진 탐색으로 찾아
*  출력할 수도 있다. 또한 모든 출력은 파일에 한다.
*
* 프로그램 작성자: 이세용 (2023년 8월 31일),
* 최종 수정 및 보완 : Version 1.0, 2023년 8월 31일 (이세용).
*
* =========================================================================================
* 프로그램 수정/보완 이력
* =========================================================================================
* 프로그램 수정/ 보완작업자      일자      수정/보완 내용
* 이세용           2023/08/31    v1.0
*
*
* =========================================================================================
*/


#include <iostream> // 기본 라이브러리
#include <iomanip> // 출력 라이브러리
#include <fstream> // 파일 입출력 라이브러리
#include "Student.h" // 헤더파일 상속
using namespace std;
#define NUM_STUDENTS 5000 // 학생 수 정의
#define NUM_SEARCH 5 // 
#define NUM_FIRST_LAST_BLOCK 100

int* genBigRandArray(int num_rands, int offset);

void main()
{
	ofstream fout; // 출력할 파일
	int* student_ids;
	Student* students, * pSt;
	char name[16];
	int student_search[NUM_SEARCH] = { 1, 123, 999, 2500, 4999 }; // 검색할 학생 번호
	fout.open("output.txt"); // "output.txt" 파일 열기
	if (fout.fail()) // 열 수 없다면 오류 메세지 출력 후 종료
	{
		cout << "Error in opening output.txt" << endl;
		exit;
	}
	student_ids = (int*)calloc(NUM_STUDENTS, sizeof(int)); // st_id 동적 할당
	students = (Student*)calloc(NUM_STUDENTS, sizeof(Student)); // 구조체 students 동적 할당
	student_ids = genBigRandArray(NUM_STUDENTS, 0); // st_id에 대해 큰 난수 배열 생성
	initStudents(students, student_ids, NUM_STUDENTS); // 만든 난수 배열을 students에 넣어줌
	//printStudentIDs(students, NUM_STUDENTS);
	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK); // 만든 students 출력
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS); // 학번에 오름차순으로 선택 정렬해 students를 만들어 줌
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK); // 정렬한 students 출력
	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) : " << endl;
	sortStudentsByGPA_ID(students, NUM_STUDENTS); // gpa에 내림차순, gpa가 같다면 students에 오름차순으로 만들기
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK); // 정렬한 students 출력
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS); // 이진탐색을 위해 다시 선택정렬 수행
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK); // 정렬한 students 출력
	fout << endl << endl;
	fout << "Searching student with student_ID : " << endl;
	for (int i = 0; i < NUM_SEARCH; i++) // 학생을 st_id로 찾기 위해 반복문 수행
	{
		pSt = searchStudentByID(students, NUM_STUDENTS, student_search[i]); // 이진 탐색
		fout << "Student search by ID (" << setw(4) << student_search[i] << ") : ";
		if (pSt != NULL) // 이진탐색에서 찾았을 경우 출력
			fprintStudent(fout, pSt);
		else // 찾지 못했을 경우 에러 메세지 출력
			fout << "NULL - student was not found !!";
		fout << endl;
	}
	fout.close(); // 파일 사용 후에는 꼭 닫아줌
}

int* genBigRandArray(int num_rands, int offset) // 큰 난수 배열 생성
{
	srand(time(0)); // 랜덤값이 항상 다른값이 나오게 하기 위해 time을 사용
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