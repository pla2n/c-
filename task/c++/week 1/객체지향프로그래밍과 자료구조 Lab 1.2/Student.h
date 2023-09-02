/**
* 파일명: "Student.h (Lab01 구조체 struct Student 설계 및 구현)"
* 프로그램의 목적 및 기본 기능:
*- 이 프로그램은 헤더파일로써 구조체와 함수 원형을 정의해 다양한 소스 파일에서 이용할 수
*  있도록 해준다. 
*
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
/* Student.h */
#include <iostream>
using namespace std;
typedef struct // Student 구조체 정의
{
	int st_id;
	char name[16];
	char dept[16];
	int grade;
	double gpa;
} Student;

// 함수 원형 정의
void initStudents(Student students[], int st_ids[], int num_students);
void fprintStudent(ostream& fout, Student* pSt);
void fprintStudentIDs(ostream& fout, Student students[], int num_students);
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
void sortStudentsByID(Student students[], int num_students);
void sortStudentsByGPA_ID(Student students[], int num_students);
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
Student* searchStudentByID(Student students[], int num_students, int st_ID);