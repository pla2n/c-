/**
* 파일명: "main.cpp"
* 프로그램의 목적 및 기본 기능:
	*- 이 프로그램은
*
*
*
* 프로그램 작성자: 이세용 (2023년 9월 1일),
* 최종 수정 및 보완 : Version 1.0, 2023년 9월 4일 (이세용).
*
* =========================================================================================
* 프로그램 수정/보완 이력
* =========================================================================================
* 프로그램 수정/ 보완작업자      일자      수정/보완 내용
* 이세용           2023/09/01    v1.0
*
*
* =========================================================================================
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"
using namespace std;
#define NUM_STUDENTS 5000
#define NUM_SEARCH 5
#define NUM_FIRST_LAST_BLOCK 100

int* genBigRandArray(int num_rands, int offset);

void main()
{
	ofstream fout;
	int* student_ids;
	Student* students, * pSt;
	int student_search[NUM_SEARCH] = { 1, 123, 999, 2500, 4999 };
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Error in opening output.txt" << endl;
		exit;
	}
	student_ids = (int*)calloc(NUM_STUDENTS, sizeof(int));
	students = (Student*)calloc(NUM_STUDENTS, sizeof(Student));
	student_ids = genBigRandArray(NUM_STUDENTS, 0);
	initStudents(students, student_ids, NUM_STUDENTS);
	//printStudentIDs(students, NUM_STUDENTS);
	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) : " << endl;
	sortStudentsByGPA_ID(students, NUM_STUDENTS); // non-increasing order
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	fout << endl << endl;
	fout << "Searching student with student_ID : " << endl;
	for (int i = 0; i < NUM_SEARCH; i++)
	{
		pSt = searchStudentByID(students, NUM_STUDENTS, student_search[i]);
		fout << "Student search by ID (" << setw(4) << student_search[i] << ") : ";
		if (pSt != NULL)
			fprintStudent(fout, pSt);
		else
			fout << "NULL - student was not found !!";
		fout << endl;
	}
	fout.close();
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