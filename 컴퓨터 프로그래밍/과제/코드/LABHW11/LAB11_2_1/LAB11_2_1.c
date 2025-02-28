// 20201012 컴퓨터학과 임소정
// LAB 11_2_1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
// typedef 를 사용하여 Student 를 정의
typedef struct student Student;

void printStudent(Student *aStudent)
{
	printf("%s\t", aStudent->name);
	printf("%d\t%d\t%d\n", aStudent->midterm, aStudent->final, aStudent->average);
}
void readStudentScore(Student *aStudent)
{
	printf("Enter student name: "); //a)
	scanf("%s", aStudent->name); //b)
	printf("Enter midterm and final score: "); //c)
	scanf("%d %d", &aStudent->midterm, &aStudent->final); //d)
}
void calculateStudentAverage(Student *aStudent)
{
	aStudent->average = (aStudent->midterm + aStudent->final)/2;
}

int main(void)
{
	Student s[40];
	int num, i;
	printf("Enter a number of student:");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		readStudentScore(&s[i]);
	}
	for (i = 0; i < num; i++)
		calculateStudentAverage(&s[i]);
	printf("\n이름\t중간\t학기말\t평균\n");
	for (i = 0; i < num; i++)
		printStudent(&s[i]);
}