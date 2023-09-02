/**
* 파일명: "Student.cpp (Lab01 구조체 struct Student 설계 및 구현)"
* 프로그램의 목적 및 기본 기능:
*- 이 프로그램은 main.cpp에서 사용하는 함수 원형들이 들어 있다.
* 모든 출력은 파일에 한다.
*
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



#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"

void initStudents(Student students[], int st_ids[], int num_students)
{
	int len;
	srand(time(0)); // 항상 랜덤한 값을 얻기위해 time 사용
	for (int i = 0; i < num_students; i++) { // 학생 수 만큼 할당
		students[i].st_id = st_ids[i]; // 학번은 st_ids 배열에서 받아와서 넣어줌
		len = rand() % 11 + 5; // name의 자릿수가 5~15임 그 사이의 len값 만들어 줌
		students[i].name[0] = 'A' + rand() % 26; // 이름의 첫번째 문자는 대문자이기 때문에 따로 빼줌
		for (int j = 1; j < len; j++)
			students[i].name[j] = 'a' + rand() % 26; // rand로 나온 길이만큼 name에 a-z까지 할당
		students[i].name[len] = '\0'; // c에서는 마지막 값을 NULL값을 줘야 컴파일러가 알아먹음

		len = rand() % 3 + 3; // name과 메커니즘이 같다 3~5 자릿수의 len값 만들어 dept에 할당
		for (int j = 0; j < len; j++)
			students[i].dept[j] = 'A' + rand() % 26;
		students[i].dept[len] = '\0';

		students[i].grade = rand() % 8 + 1; // 1~8까지의 rand값 생성
		students[i].gpa = (rand() % 10000) / 100.0; // 0.00 ~ 99.99까지의 rand값 생성
	}
}
void fprintStudent(ostream& fout, Student* pSt)
{
	fout.setf(ios::fixed); // 소수점 이하 자릿수가 고정되어 출력
	fout.setf(ios::showpoint); // 숫자가 소수점 이하 자릿수를 가질 때 0이 아닌 숫자를 항상 표시
	fout.precision(2); // 소수점 이하 2자리까지 출력하게 함

	fout << "Student(ID: " << setw(4) << pSt->st_id; // Student 구조체의 구성요소들 출력, setw로 자릿수 지정
	fout << ", Name: " << setw(16) << pSt->name;
	fout << ", Dept: " << setw(7) << pSt->dept;
	fout << ", Grade: " << setw(2) << pSt->grade;
	fout << ", GPA: " << setw(4) << pSt->gpa <<")";
}
void fprintStudentIDs(ostream& fout, Student students[], int num_students)
{
	Student* pSt;
	int count = 0;
	for (int i = 0; i < num_students; i++)
	{
		pSt = &students[i]; // students[i]의 주소값을 pSt에 저장해 사용
		fout << setw(6) << pSt->st_id; // st_id를 6자리에 걸쳐 출력
		count++;
		if ((count % 20) == 0) // 20번 출력될 때마다 줄을 바꿔서 다시 출력
			fout << endl;
	}
}
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2) // num_first_last * 2 보다 num_students가 작다면 
	{ // 굳이 두번에 나눠서 배열 앞의 값들과 뒤의 값들을 출력하지 않는다.
		for (int i = 0; i < num_students; i++)
		{
			pSt = &students[i];
			fout << setw(6) << pSt->st_id;
			count++;
			if ((count % 20) == 0)
				fout << endl;
		}
		return;
	}
	for (int i = 0; i < num_first_last; i++) // 배열의 앞의 num_first_last만큼의 students를 출력
	{
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << " . . . . . " << endl;
	for (int i = num_students - num_first_last; i < num_students; i++)
	{ // 배열의 뒤의 num_first_last만큼의 students를 출력
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}
void sortStudentsByID(Student students[], int num_students)
{
	int min;
	Student tmp;
	for (int i = 0; i < num_students-1; i++) { // 선택 정렬, 마지막값은 중복되기에 반복 x, 오름차순
		min = i; // 기준값 지정 (최소값)
		for (int j = i+1; j < num_students; j++) { // 기준값과 비교할 값들을 찾아줌
			if (students[j].st_id < students[min].st_id) // 기준값보다 작으면 기준값 변경
				min = j;
		}
		if (min != i) { // 기준값이 바뀌었다면 students 배열에서 서로 값을 바꿔줌
			tmp = students[i];
			students[i] = students[min];
			students[min] = tmp;
		}
	}
}
void sortStudentsByGPA_ID(Student students[], int num_students)
{
	int max;
	Student tmp;
	for (int i = 0; i < num_students-1; i++) { // sortStudentsByID와 구현 방법이 비슷하지만 오름차순이 아닌 내림차순이 되어야 함
		max = i; // 이번에는 기준값이 최대값
		for (int j = i + 1; j < num_students-1; j++) {
			if (students[j].gpa > students[max].gpa) // 기준값보다 큰 값이 있다면 기준값 변경
				max = j;
			else if (students[j].gpa == students[max].gpa) { // gpa가 서로 같다면
				if (students[j].st_id < students[max].st_id) // st_id가 작은걸 기준값으로 사용
					max = j;
			}
		}
		if (max != i) { // 기준값이 바뀌었다면, 서로 값을 바꿔 줌
			tmp = students[i];
			students[i] = students[max];
			students[max] = tmp;
		}
	}
}
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{ // fprintBigArrayOfStudent_IDs와 매커니즘이 같다
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2)
	{
		for (int i = 0; i < num_students; i++)
		{
			pSt = &students[i];
			fout << "(" << setw(4) << pSt->gpa << ", ";
			fout << setw(4) << pSt->st_id << ")  ";
			count++;
			if ((count % 20) == 0)
				fout << endl;
		}
		return;
	}
	for (int i = 0; i < num_first_last; i++)
	{
		pSt = &students[i];
		fout << "(" << setw(4) << pSt->gpa << ", ";
		fout << setw(4) << pSt->st_id << ")  ";
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << " . . . . . " << endl;
	for (int i = num_students - num_first_last; i < num_students; i++)
	{
		pSt = &students[i];
		fout << "(" << setw(4) << pSt->gpa << ", ";
		fout << setw(4) << pSt->st_id << ")  ";
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}
Student* searchStudentByID(Student students[], int num_students, int st_ID)
{
	int start, end, mid;
	start = 0;
	end = num_students;
	while (start < end) { // 이진 탐색
		mid = (start + end) / 2; // mid값 생성
		if (students[mid].st_id == st_ID) // mid에 있는 값이 찾는 값이면 반환
			return &students[mid];
		else if (students[mid].st_id < st_ID) // mid보다 st_ID값이 큰 곳에 있다면
			start = mid + 1; // start 값을 mid+1로 크게 만들어 줌
		else // mid보다 st_ID값이 작은 곳에 있다면
			end = mid - 1; // end 값을 mid-1로 작게 만들어 줌
	}
	return NULL; // 이진 탐색으로 찾지 못했다면, NULL을 return
}