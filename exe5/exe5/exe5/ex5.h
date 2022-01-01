/***********************
* Artiom Divak
* 319339198
* Group 01 - CS
* exe5
***********************/

#ifndef MAIN_C_EX5_H   /* Include guard */
#define MAIN_C_EX5_H

typedef struct {
	char curseID[6];
	char curseName[30];

}Curses;

typedef struct {
	char* name;
	char* cursesID;
	char* grades;
	struct	Student* next;
}Student;

void newOrUpdateCurse(Curses* allCurses, int* curseNumber);
int newOrUpdateStudent(Student* firstStudent, Curses* allCurses, int numOfCurses);
void removeStudent(Student* firstStudent, Curses* allCurses, int numOfCurses);
void getAllCurseStudents(Student* firstStudent, Curses* allCurses, int numOfCurses);
void CursesAggregation(Student* firstStudent, Curses* allCurses, int numOfCurses);
void freeStudent(Student* firstStudent);
#endif // MAIN_C_EX5_H
