/**
* 파일명: "객체지향프로그래밍과자료구조 Homework 1.2.cpp"
* 프로그램의 목적 및 기본 기능:
	*- 이 프로그램은
*
*
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
/* Student.h */
#include <iostream>
using namespace std;
typedef struct
{
	int st_id;
	char name[16];
	char dept[16];
	int grade;
	double gpa;
} Student;
void initStudents(Student students[], int st_ids[], int num_students);
void fprintStudent(ostream& fout, Student* pSt);
void fprintStudentIDs(ostream& fout, Student students[], int num_students);
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
void sortStudentsByID(Student students[], int num_students);
void sortStudentsByGPA_ID(Student students[], int num_students);
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
Student* searchStudentByID(Student students[], int num_students, int st_ID);
