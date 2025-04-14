#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<limits>
#include<fstream>
#include<cstring>
using namespace std;

typedef struct DayofBirth;
struct DayofBirth {
	int day;
	int month;
	int year;
};

typedef struct Student;
struct Student {
	char* ID;
	char* Name;
	DayofBirth BirthDay;
	char* Major;
};

bool isLeapYear(int year);
bool isDays(int month, int year, int day);

void getStudent(Student& a);
void printStudent(Student a);

void getStudents(Student a[], int& n);
void getNewStudent(Student a[], int& n);
void printStudents(Student a[], int n);
void deleteStudent(Student a[], int& n);
void updateStudent(Student a[], int& n);

void writeStudents(Student a[], int n);
void readStudents(Student a[], int& n);

void printMenu(int& choice);
void menu();