/**
* ���ϸ�: "��ü�������α׷��ְ��ڷᱸ�� Homework 1.2.cpp"
* ���α׷��� ���� �� �⺻ ���:
	*- �� ���α׷���
*
*
*
* ���α׷� �ۼ���: �̼��� (2023�� 8�� 30��),
* ���� ���� �� ���� : Version 1.0, 2023�� 8�� 30�� (�̼���).
*
* =========================================================================================
* ���α׷� ����/���� �̷�
* =========================================================================================
* ���α׷� ����/ �����۾���      ����      ����/���� ����
* �̼���           2023/08/30    v1.0
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
