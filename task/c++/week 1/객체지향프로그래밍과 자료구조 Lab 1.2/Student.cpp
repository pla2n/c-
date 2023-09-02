/**
* ���ϸ�: "Student.cpp (Lab01 ����ü struct Student ���� �� ����)"
* ���α׷��� ���� �� �⺻ ���:
*- �� ���α׷��� main.cpp���� ����ϴ� �Լ� �������� ��� �ִ�.
* ��� ����� ���Ͽ� �Ѵ�.
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



#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"

void initStudents(Student students[], int st_ids[], int num_students)
{
	int len;
	srand(time(0)); // �׻� ������ ���� ������� time ���
	for (int i = 0; i < num_students; i++) { // �л� �� ��ŭ �Ҵ�
		students[i].st_id = st_ids[i]; // �й��� st_ids �迭���� �޾ƿͼ� �־���
		len = rand() % 11 + 5; // name�� �ڸ����� 5~15�� �� ������ len�� ����� ��
		students[i].name[0] = 'A' + rand() % 26; // �̸��� ù��° ���ڴ� �빮���̱� ������ ���� ����
		for (int j = 1; j < len; j++)
			students[i].name[j] = 'a' + rand() % 26; // rand�� ���� ���̸�ŭ name�� a-z���� �Ҵ�
		students[i].name[len] = '\0'; // c������ ������ ���� NULL���� ��� �����Ϸ��� �˾Ƹ���

		len = rand() % 3 + 3; // name�� ��Ŀ������ ���� 3~5 �ڸ����� len�� ����� dept�� �Ҵ�
		for (int j = 0; j < len; j++)
			students[i].dept[j] = 'A' + rand() % 26;
		students[i].dept[len] = '\0';

		students[i].grade = rand() % 8 + 1; // 1~8������ rand�� ����
		students[i].gpa = (rand() % 10000) / 100.0; // 0.00 ~ 99.99������ rand�� ����
	}
}
void fprintStudent(ostream& fout, Student* pSt)
{
	fout.setf(ios::fixed); // �Ҽ��� ���� �ڸ����� �����Ǿ� ���
	fout.setf(ios::showpoint); // ���ڰ� �Ҽ��� ���� �ڸ����� ���� �� 0�� �ƴ� ���ڸ� �׻� ǥ��
	fout.precision(2); // �Ҽ��� ���� 2�ڸ����� ����ϰ� ��

	fout << "Student(ID: " << setw(4) << pSt->st_id; // Student ����ü�� ������ҵ� ���, setw�� �ڸ��� ����
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
		pSt = &students[i]; // students[i]�� �ּҰ��� pSt�� ������ ���
		fout << setw(6) << pSt->st_id; // st_id�� 6�ڸ��� ���� ���
		count++;
		if ((count % 20) == 0) // 20�� ��µ� ������ ���� �ٲ㼭 �ٽ� ���
			fout << endl;
	}
}
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2) // num_first_last * 2 ���� num_students�� �۴ٸ� 
	{ // ���� �ι��� ������ �迭 ���� ����� ���� ������ ������� �ʴ´�.
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
	for (int i = 0; i < num_first_last; i++) // �迭�� ���� num_first_last��ŭ�� students�� ���
	{
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << " . . . . . " << endl;
	for (int i = num_students - num_first_last; i < num_students; i++)
	{ // �迭�� ���� num_first_last��ŭ�� students�� ���
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
	for (int i = 0; i < num_students-1; i++) { // ���� ����, ���������� �ߺ��Ǳ⿡ �ݺ� x, ��������
		min = i; // ���ذ� ���� (�ּҰ�)
		for (int j = i+1; j < num_students; j++) { // ���ذ��� ���� ������ ã����
			if (students[j].st_id < students[min].st_id) // ���ذ����� ������ ���ذ� ����
				min = j;
		}
		if (min != i) { // ���ذ��� �ٲ���ٸ� students �迭���� ���� ���� �ٲ���
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
	for (int i = 0; i < num_students-1; i++) { // sortStudentsByID�� ���� ����� ��������� ���������� �ƴ� ���������� �Ǿ�� ��
		max = i; // �̹����� ���ذ��� �ִ밪
		for (int j = i + 1; j < num_students-1; j++) {
			if (students[j].gpa > students[max].gpa) // ���ذ����� ū ���� �ִٸ� ���ذ� ����
				max = j;
			else if (students[j].gpa == students[max].gpa) { // gpa�� ���� ���ٸ�
				if (students[j].st_id < students[max].st_id) // st_id�� ������ ���ذ����� ���
					max = j;
			}
		}
		if (max != i) { // ���ذ��� �ٲ���ٸ�, ���� ���� �ٲ� ��
			tmp = students[i];
			students[i] = students[max];
			students[max] = tmp;
		}
	}
}
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{ // fprintBigArrayOfStudent_IDs�� ��Ŀ������ ����
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
	while (start < end) { // ���� Ž��
		mid = (start + end) / 2; // mid�� ����
		if (students[mid].st_id == st_ID) // mid�� �ִ� ���� ã�� ���̸� ��ȯ
			return &students[mid];
		else if (students[mid].st_id < st_ID) // mid���� st_ID���� ū ���� �ִٸ�
			start = mid + 1; // start ���� mid+1�� ũ�� ����� ��
		else // mid���� st_ID���� ���� ���� �ִٸ�
			end = mid - 1; // end ���� mid-1�� �۰� ����� ��
	}
	return NULL; // ���� Ž������ ã�� ���ߴٸ�, NULL�� return
}