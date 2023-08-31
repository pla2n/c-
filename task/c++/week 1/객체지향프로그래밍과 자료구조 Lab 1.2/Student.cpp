#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"

void initStudents(Student students[], int st_ids[], int num_students)
{
	int len;
	srand(time(0));
	for (int i = 0; i < num_students; i++) {
		students[i].st_id = st_ids[i];
		len = rand() % 11 + 5;
		students[i].name[0] = 'A' + rand() % 26;
		for (int j = 1; j < len; j++)
			students[i].name[j] = 'a' + rand() % 26;
		students[i].name[len] = '\0';

		len = rand() % 3 + 3;
		for (int j = 0; j < len; j++)
			students[i].dept[j] = 'A' + rand() % 26;
		students[i].dept[len] = '\0';

		students[i].grade = rand() % 8 + 1;
		students[i].gpa = (rand() % 10000) / 100.0;
	}
}
void fprintStudent(ostream& fout, Student* pSt)
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);

	fout << "Student(ID: " << setw(4) << pSt->st_id;
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
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2)
	{
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
	for (int i = 0; i < num_first_last; i++)
	{
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << " . . . . . " << endl;
	for (int i = num_students - num_first_last; i < num_students; i++)
	{
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
	for (int i = 0; i < num_students-1; i++) {
		min = i;
		for (int j = i+1; j < num_students; j++) {
			if (students[j].st_id < students[min].st_id)
				min = j;
		}
		if (min != i) {
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
	for (int i = 0; i < num_students-1; i++) {
		max = i;
		for (int j = i + 1; j < num_students-1; j++) {
			if (students[j].gpa > students[max].gpa)
				max = j;
			else if (students[j].gpa == students[max].gpa) {
				if (students[j].st_id < students[max].st_id)
					max = j;
			}
		}
		if (max != i) {
			tmp = students[i];
			students[i] = students[max];
			students[max] = tmp;
		}
	}
}
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
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
	while (start < end) {
		mid = (start + end) / 2;
		if (students[mid].st_id == st_ID)
			return &students[mid];
		else if (students[mid].st_id < st_ID)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return NULL;
}