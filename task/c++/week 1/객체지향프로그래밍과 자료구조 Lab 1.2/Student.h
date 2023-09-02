/**
* ���ϸ�: "Student.h (Lab01 ����ü struct Student ���� �� ����)"
* ���α׷��� ���� �� �⺻ ���:
*- �� ���α׷��� ������Ϸν� ����ü�� �Լ� ������ ������ �پ��� �ҽ� ���Ͽ��� �̿��� ��
*  �ֵ��� ���ش�. 
*
*
*
* ���α׷� �ۼ���: �̼��� (2023�� 8�� 31��),
* ���� ���� �� ���� : Version 1.0, 2023�� 8�� 31�� (�̼���).
*
* =========================================================================================
* ���α׷� ����/���� �̷�
* =========================================================================================
* ���α׷� ����/ �����۾���      ����      ����/���� ����
* �̼���           2023/08/31    v1.0
*
*
* =========================================================================================
*/
/* Student.h */
#include <iostream>
using namespace std;
typedef struct // Student ����ü ����
{
	int st_id;
	char name[16];
	char dept[16];
	int grade;
	double gpa;
} Student;

// �Լ� ���� ����
void initStudents(Student students[], int st_ids[], int num_students);
void fprintStudent(ostream& fout, Student* pSt);
void fprintStudentIDs(ostream& fout, Student students[], int num_students);
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
void sortStudentsByID(Student students[], int num_students);
void sortStudentsByGPA_ID(Student students[], int num_students);
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
Student* searchStudentByID(Student students[], int num_students, int st_ID);