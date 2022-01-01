/***********************
* Artiom Divak
* 319339198
* Group 01 - CS
* exe5
***********************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ex5.h"
typedef struct Curses {
	char curseID[6];
	char curseName[30];
}Curses;

typedef struct Student {
	char* name;
	char* cursesID;
	char* grades;
	struct	Student* next;
}Student;

/******************
* Function Name:strLength
* Input: char * str (input string of the user)
* Output: returns length of the string else returns 0
* Function Operation: do a while loop till /0
******************/
int strLength(char* str, int startPoint) {
	int i = startPoint;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

/******************
* Function Name:checkIfNumbers
* Input: char* curse, int index(from this index),int num(number of numbers that should be)
* Output: returns 1 if all chars are numbers is valid else returns 0
* Function Operation: check if str contains the numbers of numbers one by one
******************/
int checkIfNumbers(char* curse, int index, int num) {

	for (int i = 0; i < num;i++) {
		if (curse[i + index] > '9' || curse[i + index] < '0') {
			return 0;
		}
	}
	return 1;
}

/******************
* Function Name:afterSpace
* Input: char * curse (input string of the user)
* Output: returns number of spaces in the given str from the start
* Function Operation: returns number of spaces in the given str from the start
******************/
int afterSpace(char* curse, int startPoint) {
	int index = startPoint;
	while (curse[index] == ' ') {
		index++;
	}
	return index;
}

/******************
* Function Name:validCurse
* Input: char * curse (input string of the user)
* Output: returns 1 if the curse is valid else returns 0
* Function Operation: check if the user unput was valid
******************/
int validCurse(char* curse) {
	int index = afterSpace(curse, 0);
	if (!checkIfNumbers(curse, index, 5)) {
		return 0;
	}
	index = index + 5;
	if (afterSpace(curse, index) == 0) {
		return 0;
	}
	index = afterSpace(curse, index);
	if (strLength(curse, index) >= 30) {
		return 0;
	}
	for (int i = 0; i < strLength(curse, index);i++) {
		if (curse[i + index] == '\n') {
			if (i == 0) {
				return 0;
			}
			break;
		}
		if (curse[i + index] != ' ' && (curse[i + index] > '9' || curse[i + index] < '0') && (curse[i + index] > 'Z' || curse[i + index] < 'A') && (curse[i + index] < 'a' || curse[i + index] >'z'))
		{
			return 0;
		}
	}
	return 1;
}


/******************
* Function Name:getCurseIDAndCurseName
* Input: char * str, char * curseName
* Output: NONE (returns the curse Id inside curseID )
* Function Operation: returns the curse Id inside curseID r
******************/
void getCurseID(char* str, char* curseID, int index) {
	int newindex = afterSpace(str, index);
	for (int i = 0;i < 5;i++) {
		*(curseID + i) = *(str + newindex + i);
	}
	*(curseID + 5) = '\0';
}
/******************
* Function Name:getCurseName
* Input: char * str,char * curseID
* Output: NONE (returns the curse name inside curseName)
* Function Operation: returns the curse Id inside curseName
******************/
void getCurseName(char* str, char* curseName) {
	int index = afterSpace(str, 0);
	index = afterSpace(str, index + 5);
	int count = 0;
	for (int i = 0;i < 30 && *(str + index + i) != 0;i++) {
		*(curseName + i) = *(str + index + i);
		count = i;
	}
	*(curseName + count) = '\0';
}
/******************
* Function Name:copyStrings
* Input: char * origin, char * newStr
* Output: NONE
* Function Operation: copy the string from origin to newStr
******************/
void copyStrings(char* origin, char* newStr) {
	int originLength = strLength(origin, 0);
	for (int i = 0;i < originLength;i++) {
		newStr[i] = origin[i];
		newStr[i + 1] = '\0';
	}

}


/******************
* Function Name:newOrUpdateCurse
* Input: Curses allCurses, int * curseNumber
* Output: NONE
* Function Operation: adds ot update a curse
******************/
void newOrUpdateCurse(Curses* allCurses, int* curseNumber) {
	scanf(" ");
	char curse[200] = { 0 };
	scanf("%c");
	fgets(curse, 200, stdin);
	if (validCurse(curse)) {
		char curseID[6];
		char curseName[31];
		getCurseID(curse, curseID, 0);
		getCurseName(curse, curseName);
		//printf("!!!!!!!!!!! %s %s",curseID,curseN);
		Curses* tempCurse;
		int updated = 0;
		for (int i = 0; i < *curseNumber;i++) {
			tempCurse = &allCurses[i];
			if (strcmp(curseID, tempCurse->curseID) == 0) {
				updated = 1;
				copyStrings(curseID, allCurses[0].curseName);
				printf("Class \"%s %s\" updated.\n", curseID, curseName);
			}
		}
		if (updated == 0) {
			tempCurse = &allCurses[*curseNumber];
			copyStrings(curseID, allCurses[*curseNumber].curseID);
			copyStrings(curseName, allCurses[*curseNumber].curseName);
			printf("Class \"%s %s\" added.\n", allCurses[*curseNumber].curseID, allCurses[*curseNumber].curseName);
			*curseNumber = *curseNumber + 1;
		}

	}
	else {
		printf("Error: invalid class number or name\n");
	}
}

/******************
* Function Name:validStudentInput
* Input: char * students,int * index
* Output: int return 1 if the students contains only letters else returns 0
* Function Operation: int return 1 if the students contains only letters else returns 0
******************/
int checkOnlyLetters(char* students, int* index) {
	int count = *index;
	int spaces = 0;
	while (*(students + count) != ':')
	{
		if ((*(students + count) > 'Z' || *(students + count) < 'A') && (*(students + count) > 'z' || *(students + count) < 'a') && *(students + count) != ' ') {
			return 0;
		}
		if (*(students + count) == ' ') {
			if (spaces > 0) {
				return 0;
			}
			spaces++;
		}
		count++;
		if (*(students + count) == '\n' || *(students + count) == '\0')
		{
			return 0;
		}
	}
	*index = count;
	return 1;
}

/******************
* Function Name:checkCurseExist
* Input: char* curseID, Curses * allCurses
* Output: int 1 if the curse exist inside all curses else returns 0
* Function Operation: 1 if the curse exist inside all curses else returns 0
******************/
int checkCurseExist(char* curseID, Curses* allCurses, int numOfCurses) {
	for (int i = 0;i <= numOfCurses;i++) {
		if (strcmp(allCurses[i].curseID, curseID) == 0) {
			return 1;
		}
	}
	return 0;
}

/******************
* Function Name:validStudentInput
* Input: char * students
* Output: int 1 if the command was wriiten by the format else returns 0
* Function Operation: 1 if the command was wriiten by the format else returns 0
******************/
int validStudentInput(char* students, Curses* allCurses, int numOfCurses) {
	int index = afterSpace(students, 0);
	if (!checkOnlyLetters(students, &index)) {
		return 0;
	}
	if (students[index] == '\n' || students[index] == '\0') {
		return 0;
	}
	index++;
	while (students[index] != '\n' && students[index] != '\0') {
		index = afterSpace(students, index);
		if (checkIfNumbers(students, index, 5) == 0) {
			return 0;
		}
		char curseID[6];
		getCurseID(students, curseID, index);
		if (checkCurseExist(curseID, allCurses, numOfCurses) == 0) {
			return 0;
		}
		index = index + 5;
		index = afterSpace(students, index);
		if (students[index] != ',') {
			return 0;
		}
		index++;
		index = afterSpace(students, index);
		for (int i = 0;i < 3;i++) {
			if (!checkIfNumbers(students, index + i, 1)) {
				if (students[index + i] != ';' && (students[index] != '\n' && students[index] != '\0')) {
					return 0;
				}
				else {
					index = index + i + 1;
					break;
				}
			}
			if (i == 2) {
				if (students[index] != '1' || students[index + 1] != '0' || students[index + 2] != '0') {
					return 0;
				}
				index = index + 3;
				index = afterSpace(students, index);
				if (students[index] != ';' && (students[index] != '\n' && students[index] != '\0')) {
					return 0;
				}
				index++;
			}
		}
	}
	return 1;
}

/******************
* Function Name:clearString
* Input: char * str,int length
* Output: NONE
* Function Operation: put \0 in the string
******************/
void clearString(char* str, int length) {
	for (int i = 0; i < length; i++) {
		str[i] = '\0';
	}
}

/******************
* Function Name:getStudentCurses
* Input: char * str,char * curses
* Output: NONE
* Function Operation: get from the command student curses
******************/
void getStudentCurses(char* str, char* curses) {
	clearString(curses, 26);
	int index = afterSpace(str, 0);
	int count = 0;
	while (str[index] != ':') {
		index++;
	}
	index++;
	while (str[index] != '\0' && str[index] != '\n') {
		index = afterSpace(str, index);
		for (int i = 0;i < 5;i++) {
			curses[count] = str[index];
			count++;
			index++;
		}
		while (str[index] != '\0' && str[index] != '\n' && str[index] != ';') {
			index++;
		}
		index++;
	}
	count++;
	curses[count] = '\0';
}

/******************
* Function Name:getStudentCurses
* Input: char * str,char * curses
* Output: NONE
* Function Operation: get from the command student grades
******************/
void getStudentGrades(char* str, char* grades) {
	clearString(grades, 26);
	int index = afterSpace(str, 0);
	int count = 0;
	while (str[index] != ':') {
		index++;
	}
	index++;
	while (str[index] != '\0' && str[index] != '\n') {
		index = afterSpace(str, index);
		index = index + 5;
		index = afterSpace(str, index);
		index++;
		index = afterSpace(str, index);
		for (int i = 0;i < 5;i++) {
			grades[count * 5 + i] = '.';
		}
		grades[count * 5 + 5] = '\0';
		int num = 0;
		for (int i = 0; i < 3; i++)
		{
			if (str[index + i] == ';' || str[index + i] == '\n' || str[index + i] == '\0') {
				break;
			}
			num++;
		}
		for (int i = num;i > 0;i--) {
			grades[(count + 1) * 5 - 1 - (num - i)] = str[index + i - 1];
		}
		count++;
		index = index + num + 1;

	}
}

/******************
* Function Name:getStudentName
* Input: char * str,char * student
* Output: NONE
* Function Operation: get from the command student name
******************/
void getStudentName(char* str, char* student) {
	int index = afterSpace(str, 0);
	int count = 0;
	while (str[index + count] != ':') {
		student[count] = str[index + count];
		count++;

	}
	student[count] = '\0';
}

/******************
* Function Name:printUpdatedStudent
* Input:Curses* allCurses, char * studentName, char * studentCurse, char * studentGrade, int numberOfCurses
* Output: NONE
* Function Operation:  prints the STudent name curse and grade
******************/
void printUpdatedStudent(Curses* allCurses, char* studentName, char* studentCurse, char* studentGrade, int numberOfCurses, char* str) {
	char* test;
	for (int i = 0;i < numberOfCurses;i++) {
		if (strcmp(allCurses[i].curseID, studentCurse) == 0) {
			test = allCurses[i].curseName;
		}
	}
	char grade[4];
	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (studentGrade[i] != '.') {
			grade[count] = studentGrade[i];
			count++;
			grade[count] = '\0';
		}
	}
	printf("Student \"%s\" %s class \"%s %s\" with grade %s.\n", studentName, str, studentCurse, test, grade);

}

/******************
* Function Name:createStudent
* Input: char * student,Student * firstStudent
* Output: NONE
* Function Operation: adds a new Student to the list
******************/
void createLastStudent(char* student, Student* firstStudent, Curses* allCurses, int numberOfCurses, Student* newStudent, char* name, char* curses, char* grades) {
	Student* tempStudent = firstStudent;
	while (tempStudent->next != NULL) {
		tempStudent = tempStudent->next;
	}
	tempStudent->next = newStudent;
	newStudent->grades = grades;
	newStudent->name = name;
	newStudent->cursesID = curses;
	newStudent->next = NULL;
	char grade[6];
	char curse[6];
	int count = 0;
	while (curses[count * 5] != '\0') {
		for (int i = 0; i < 5;i++) {
			grade[i] = grades[count * 5 + i];
			curse[i] = curses[count * 5 + i];
		}
		curse[5] = '\0';
		grade[5] = '\0';
		char add[] = "added to";
		printUpdatedStudent(allCurses, name, curse, grade, numberOfCurses, add);
		count++;
	}
}
/******************
* Function Name:createStudent
* Input: char * student,Student * firstStudent
* Output: NONE
* Function Operation: adds a new Student to the list
******************/
void createStudent(char* student, Student* firstStudent, Curses* allCurses, int numberOfCurses) {
	Student* newStudent = (Student*)calloc(1, sizeof(Student));
	if (newStudent == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	char* name = (char*)calloc(31, sizeof(char));
	if (name == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	char* curses = (char*)calloc(26, sizeof(char));
	if (curses == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	char* grades = (char*)calloc(26, sizeof(char));
	if (grades == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	getStudentName(student, name);
	getStudentCurses(student, curses);
	getStudentGrades(student, grades);
	Student* tempStudent = firstStudent;
	Student* prevStudent;
	while (tempStudent->next != NULL) {
		prevStudent = tempStudent;
		tempStudent = tempStudent->next;
		if (strcmp(name, tempStudent->name) > 0) {
			break;
		}
	}
	if (tempStudent->next == NULL) {
		createLastStudent(student, firstStudent, allCurses, numberOfCurses, newStudent, name, curses, grades);
		return;
	}
	prevStudent->next = newStudent;
	newStudent->grades = grades;
	newStudent->name = name;
	newStudent->cursesID = curses;
	newStudent->next = tempStudent;
	char grade[6];
	char curse[6];
	int count = 0;
	while (curses[count * 5] != '\0') {
		for (int i = 0; i < 5;i++) {
			grade[i] = grades[count * 5 + i];
			curse[i] = curses[count * 5 + i];
		}
		curse[5] = '\0';
		grade[5] = '\0';
		char add[] = "added to";
		printUpdatedStudent(allCurses, name, curse, grade, numberOfCurses, add);
		count++;
	}

}

/******************
* Function Name:updateStudent
* Input:char* student,Student * firstStudent
* Output: int return 1 if update student else return 0
* Function Operation: return 1 if update student else return 0
******************/
int updateStudent(char* student, Student* firstStudent, Curses* allCurses, int numberOfCurses) {
	char name[31];
	getStudentName(student, name);
	Student* tempStudent = firstStudent->next;
	if (firstStudent->next != NULL) {
		while (tempStudent->next != NULL) {
			if (strcmp(tempStudent->name, name) == 0) {
				break;
			}
			tempStudent = tempStudent->next;
		}
		if (tempStudent->next == NULL) {
			if (strcmp(tempStudent->name, name) != 0) {
				return 0;
			}
		}
	}
	else {
		return 0;
	}
	char tmpCurses[26];
	char tmpGrades[26];
	getStudentCurses(student, tmpCurses);
	getStudentGrades(student, tmpGrades);
	char* studentCurses = tempStudent->cursesID;
	char* studentGrades = tempStudent->grades;
	int count = 0;
	while (tmpCurses[count * 5] != '\0') {
		char newCurse[6];
		for (int i = 0; i < 5;i++) {
			newCurse[i] = tmpCurses[count * 5 + i];
		}
		newCurse[5] = '\0';
		int curseNumber = 0;
		int swaped = 0;
		while (studentCurses[5 * curseNumber] != '\0') {
			char currentCurse[6];
			for (int i = 0; i < 5;i++) {
				currentCurse[i] = studentCurses[curseNumber * 5 + i];
			}
			currentCurse[5] = '\0';
			if (strcmp(currentCurse, newCurse) == 0) {
				char grade[6];
				for (int i = 0; i < 5;i++) {
					studentGrades[curseNumber * 5 + i] = tmpGrades[curseNumber * 5 + i];
					grade[i] = tmpGrades[count * 5 + i];
					swaped = 1;
				}
				grade[5] = '\0';
				char update[] = "added to";
				printUpdatedStudent(allCurses, name, currentCurse, grade, numberOfCurses, update);
				break;
			}
			curseNumber++;
		}
		if (swaped == 0) {
			char grade[6];
			for (int i = 0; i < 5;i++) {
				studentCurses[curseNumber * 5 + i] = newCurse[i];
				studentGrades[curseNumber * 5 + i] = tmpGrades[count * 5 + i];
				grade[i] = tmpGrades[count * 5 + i];
			}
			grade[5] = '\0';
			char update[] = "update on";
			printUpdatedStudent(allCurses, name, newCurse, grade, numberOfCurses, update);
		}
		count++;

	}

	return 1;
}

/******************
* Function Name:newOrUpdateStudent
* Input: Student * firstStudent, Curses * allCurses, int numOfCurses
* Output: int 1 if the input was valid else 0
* Function Operation: adds ot update a student
******************/
int newOrUpdateStudent(Student* firstStudent, Curses* allCurses, int numOfCurses) {
	char student[200];
	scanf(" %[^\n]s", student);
	if (validStudentInput(student, allCurses, numOfCurses)) {
		if (updateStudent(student, firstStudent, allCurses, numOfCurses)) {
			return 1;
		}
		createStudent(student, firstStudent, allCurses, numOfCurses);
		return 1;
	}
	else {
		return 0;
	}

}
/******************
* Function Name:  checkIfStudentHaveCurse
* Input: Student * firstStudent,char * studentName
* Output: int returns 1 if the student name exist else returns 0
* Function Operation:returns 1 if the student name exist else returns 0
******************/
int checkIfStudentHaveCurse(Student* firstStudent, char* studentName, char* curse) {
	Student* tempStudent = firstStudent->next;
	while (tempStudent->next != NULL) {
		if (strcmp(tempStudent->name, studentName) == 0) {
			break;
		}
		tempStudent = tempStudent->next;
	}
	if (strcmp(tempStudent->name, studentName) != 0) {
		return 0;
	}
	char* studentCurses = tempStudent->cursesID;
	int index = 0;
	int match = 0;
	while (studentCurses[index] != 0) {
		for (int i = 0;i < 5;i++) {
			if (studentCurses[index + i] == curse[i]) {
				match++;
			}
		}
		if (match == 5) {
			return 1;
		}
		match = 0;
		index = index + 5;
	}
	return 0;
}

/******************
* Function Name: checkIfStudentExist
* Input: Student * firstStudent,char * studentName
* Output: int returns 1 if the student name exist else returns 0
* Function Operation:returns 1 if the student name exist else returns 0
******************/
int checkIfStudentExist(Student* firstStudent, char* studentName) {
	Student* tempStudent = firstStudent->next;
	while (tempStudent != NULL) {
		if (strcmp(tempStudent->name, studentName) == 0) {
			return 1;
		}
		tempStudent = tempStudent->next;
	}
	if (strcmp(tempStudent->name, studentName) == 0) {
		return 1;
	}
	return 0;
}

/******************
* Function Name: valideRemove
* Input: char* toRemove, Curses* allCurses, int numOfCurses,Student* firstStudent
* Output: int returns 1 if the input is valid return 2 if the student dosnt have a curse returns 3 if trying to delete all student curses else retuerns 0
* Function Operation:returns 1 if the input is valid else retuerns 0
******************/
int validRemove(char* toRemove, Curses* allCurses, int numOfCurses, Student* firstStudent) {
	int index = afterSpace(toRemove, 0);
	char studentName[200];
	int count = 0;
	while (toRemove[index] != ':') {
		studentName[count] = toRemove[index];
		count++;
		index++;
	}
	if (count == 0) {
		return 0;
	}
	studentName[count] = '\0';
	if (checkIfStudentExist(firstStudent, studentName) == 0) {
		return 0;
	}
	index++;
	index = afterSpace(toRemove, index);
	if (index == '\0') {
		return 0;
	}
	Student* tempstudent = firstStudent->next;
	int numOfStudentCurses = 0;
	while (tempstudent->next != NULL) {
		if (strcmp(studentName, tempstudent->name) == 0) {
			numOfStudentCurses = strLength(tempstudent->cursesID, 0) / 5;
		}
		tempstudent = tempstudent->next;
	}
	if (numOfStudentCurses == 0) {
		if (strcmp(studentName, tempstudent->name) == 0) {
			numOfStudentCurses = strLength(tempstudent->cursesID, 0) / 5;
		}
		else {
			return 0;
		}
	}

	int numOfCursesToDelete = 0;
	while (toRemove[index] != '\0' && toRemove[index] != '\n') {
		index = afterSpace(toRemove, index);
		if (checkIfNumbers(toRemove, index, 5) == 0) {
			return 0;
		}
		char curse[6];
		numOfCursesToDelete++;
		for (int i = 0; i < 5;i++) {
			curse[i] = toRemove[i + index];
		}
		curse[5] = '\0';
		if (checkCurseExist(curse, allCurses, numOfCurses) == 0) {
			return 0;
		}
		else {
			if (checkIfStudentHaveCurse(firstStudent, studentName, curse) == 0) {
				for (int i = 0;i < numOfCurses; i++) {
					if (strcmp(curse, allCurses[i].curseID) == 0) {
						printf("Error: student is not a member of class \"%s %s\".\n", curse, allCurses[i].curseName);
						return 2;
					}
				}
			}
			if (numOfStudentCurses == numOfCursesToDelete) {
				printf("Error: student cannot be removed from all classes.\n");
				return 3;
			}
		}
		index = index + 5;
		index = afterSpace(toRemove, index);
		if (toRemove[index] != ',') {
			return 0;
		}
		index++;
	}
	return 1;
}


/******************
* Function Name:deleteCurseForStudent
* Input: Student* firstStudent, char * curse, char * name
* Output: NONE
* Function Operation: adds ot update a student
******************/
void deleteCurseForStudent(Student* firstStudent, char* curse, char* name, Curses* allCurses, int numberOfCurses) {
	Student* tempStudent = firstStudent->next;
	while (tempStudent->next != NULL) {
		if (strcmp(tempStudent->name, name) == 0) {
			break;
		}
		tempStudent = tempStudent->next;
	}
	char* curseChar = tempStudent->cursesID;
	char* gradeChar = tempStudent->grades;
	int index = 0;
	while (curseChar[index] != '\0') {
		char studentCurse[6];
		studentCurse[5] = '\0';
		for (int i = 0; i < 5; i++) {
			studentCurse[i] = curseChar[i + index];
		}
		if (strcmp(curse, studentCurse) == 0) {
			int count = index + 5;
			while (curseChar[count] != '\0') {
				curseChar[count - 5] = curseChar[count];
				gradeChar[count - 5] = gradeChar[count];
				count++;
			}
			curseChar[count - 5] = '\0';
			gradeChar[count - 5] = '\0';
			char curseName[31];
			for (int i = 0;i < numberOfCurses;i++) {
				if (strcmp(allCurses[i].curseID, studentCurse) == 0) {
					int index = 0;
					while (allCurses[i].curseName[index] != '\0') {
						curseName[index] = allCurses[i].curseName[index];
						curseName[index + 1] = '\0';
						index++;
					}
				}
			}
			printf("Student \"%s\" removed from class \"%s %s\".\n", name, curse, curseName);
		}
		index = index + 5;
	}
}

/******************
* Function Name:removeStudent
* Input: Student* firstStudent, Curses* allCurses, int numOfCurses
* Output: NONE
* Function Operation: adds ot update a student
******************/
void removeStudent(Student* firstStudent, Curses* allCurses, int numOfCurses) {
	char removeStudent[200];
	scanf(" %[^\n]s", removeStudent);
	int validResult = validRemove(removeStudent, allCurses, numOfCurses, firstStudent);
	if (validResult == 1) {
		int index = afterSpace(removeStudent, 0);
		char studentName[200];
		int count = 0;
		while (removeStudent[index] != ':') {
			studentName[count] = removeStudent[index];
			count++;
			index++;
		}
		index++;
		studentName[count] = '\0';
		while (removeStudent[index] != '\0') {
			index = afterSpace(removeStudent, index);
			char curse[6];
			for (int i = 0; i < 5;i++) {
				curse[i] = removeStudent[i + index];
			}
			curse[5] = '\0';
			deleteCurseForStudent(firstStudent, curse, studentName, allCurses, numOfCurses);
			index = index + 5;
			index = afterSpace(removeStudent, index);
			index++;
		}
		return;
	}
	else {
		if (validResult != 0) {
			return;
		}

		printf("Error: invalid name or class number\n");
	}
}

/******************
* Function Name: getAllCurseStudents
* Input: Student* firstStudent, Curses* allCurses, int numOfCurses
* Output: NONE
* Function Operation: find all the student with the curse and print them
******************/
void getAllCurseStudents(Student* firstStudent, Curses* allCurses, int numOfCurses) {
	char curse[200];
	scanf(" %[^\n]s", curse);
	char copyCurse[6];
	copyCurse[5] = '\0';
	int index = afterSpace(curse, 0);
	for (int i = 0;i < 5;i++) {
		copyCurse[i] = curse[i + index];
	}
	if (strLength(curse, 0) != 5 + index) {
		printf("Error: invalid class number1.\n");
		return;
	}
	if (checkIfNumbers(copyCurse, 0, 5) == 0) {
		printf("Error: invalid class number2.\n");
		return;
	}
	if (checkCurseExist(copyCurse, allCurses, numOfCurses) == 0) {
		printf("Error: invalid class number3.\n");
		return;
	}
	char curseName[31];
	for (int i = 0;i < numOfCurses;i++) {
		if (strcmp(allCurses[i].curseID, copyCurse) == 0) {
			for (int j = 0; j < strLength(allCurses[i].curseName, 0);j++) {
				curseName[j] = allCurses[i].curseName[j];
				curseName[j + 1] = '\0';
			}
		}
	}
	int foundStudent = 0;
	Student* tempStudent = firstStudent->next;
	while (tempStudent != NULL) {
		char* studentCurses = tempStudent->cursesID;
		char* studentGrades = tempStudent->grades;
		char* studentName = tempStudent->name;
		for (int i = 0; i < strLength(studentCurses, 0) / 5;i++) {
			int count = 0;
			for (int j = 0;j < 5;j++) {
				if (copyCurse[j] == studentCurses[i * 5 + j]) {
					count++;
				}
			}
			if (count == 5) {
				if (foundStudent == 0) {
					foundStudent = 1;
					printf("Class \"%s %s\" students:\n", copyCurse, curseName);
				}
				char grades[4];
				int index = 0;
				for (int j = 0; j < 5;j++) {
					if (studentGrades[j] != '.') {
						grades[index] = studentGrades[i * 5 + j];
						index++;
					}
				}
				index++;
				grades[index] = '\0';
				printf("%s, %s\n", studentName, grades);
			}

		}

		tempStudent = tempStudent->next;
	}
	if (foundStudent == 0) {
		printf("Class \"%s %s\" has no students.", copyCurse, curseName);
	}
}

/******************
* Function Name: averageGrade
* Input: Student* firstStudent, char* curseName, char* curseId
* Output: NONE
* Function Operation: calculate the grade of every curse by user choise
******************/
void averageGrade(Student* firstStudent, char* curseName, char* curseId) {
	Student* tempStudent = firstStudent->next;
	int numberOfStudent = 0;
	int grade = 0;
	while (tempStudent->next != NULL) {
		char curse[6];
		curse[5] = '\0';
		int index = 0;
		while (tempStudent->cursesID[index] != '\0') {
			for (int i = 0; i < 5; i++) {
				curse[i] = tempStudent->cursesID[index + i];
			}
			if (strcmp(curse, curseId) == 0) {
				numberOfStudent++;
				int power = 1;
				for (int i = 0; i < 5; i++) {
					if (tempStudent->grades[index + 4 - i] != '.') {
						grade = grade + (tempStudent->grades[index + 4 - i] - '0') * power;
						power = power * 10;
					}

				}
			}
			index = index + 5;
		}
		tempStudent = tempStudent->next;
	}
	if (numberOfStudent != 0) {
		printf("%s %s, %d\n", curseId, curseName, (grade / numberOfStudent));
	}
	else {
		printf("Class \"%s %S\" has no students.\n", curseId, curseName);
	}
}

/******************
* Function Name: maxGrade
* Input: Student* firstStudent, char* curseName, char* curseId
* Output: NONE
* Function Operation: calculate the max grade of every curse by user choise
******************/
void maxGrade(Student* firstStudent, char* curseName, char* curseId) {
	Student* tempStudent = firstStudent->next;
	int numberOfStudent = 0;
	int maxGrade = 0;
	while (tempStudent != NULL) {
		int grade = 0;
		char curse[6];
		curse[5] = '\0';
		int index = 0;
		while (tempStudent->cursesID[index] != '\0') {
			for (int i = 0; i < 5; i++) {
				curse[i] = tempStudent->cursesID[index + i];
			}
			if (strcmp(curse, curseId) == 0) {
				grade = 0;
				numberOfStudent++;
				int power = 1;
				for (int i = 0; i < 5; i++) {
					if (tempStudent->grades[index + 4 - i] != '.') {
						grade = grade + (tempStudent->grades[index + 4 - i] - '0') * power;
						power = power * 10;
					}

				}
				if (maxGrade < grade) {
					maxGrade = grade;
				}
			}
			index = index + 5;
		}
		tempStudent = tempStudent->next;
	}
	if (numberOfStudent != 0) {
		printf("%s %s, %d\n", curseId, curseName, maxGrade);
	}
	else {
		printf("Class \"%s %S\" has no students.\n", curseId, curseName);
	}
}
/******************
* Function Name: minGrade
* Input:Student* firstStudent, char* curseName, char* curseId
* Output: NONE
* Function Operation: calculate the min grade of every curse by user choise
******************/
void minGrade(Student* firstStudent, char* curseName, char* curseId) {
	Student* tempStudent = firstStudent->next;
	int numberOfStudent = 0;
	int minGrade = 100;
	while (tempStudent != NULL) {
		int grade = 0;
		char curse[6];
		curse[5] = '\0';
		int index = 0;
		while (tempStudent->cursesID[index] != '\0') {
			for (int i = 0; i < 5; i++) {
				curse[i] = tempStudent->cursesID[index + i];
			}
			if (strcmp(curse, curseId) == 0) {
				grade = 0;
				numberOfStudent++;
				int power = 1;
				for (int i = 0; i < 5; i++) {
					if (tempStudent->grades[index + 4 - i] != '.') {
						grade = grade + (tempStudent->grades[index + 4 - i] - '0') * power;
						power = power * 10;
					}

				}
				if (minGrade > grade) {
					minGrade = grade;
				}
			}
			index = index + 5;
		}
		tempStudent = tempStudent->next;
	}
	if (numberOfStudent != 0) {
		printf("%s %s, %d\n", curseId, curseName, minGrade);
	}
	else {
		printf("Class \"%s %S\" has no students.\n", curseId, curseName);
	}
}

/******************
* Function Name: sumGrade
* Input: Student* Student* firstStudent, char* curseName, char* curseId
* Output: NONE
* Function Operation: calculate the sum grade of every curse by user choise
******************/
void sumGrade(Student* firstStudent, char* curseName, char* curseId) {
	Student* tempStudent = firstStudent->next;
	int grade = 0;
	int numberOfStudent = 0;
	while (tempStudent != NULL) {
		char curse[6];
		curse[5] = '\0';
		int index = 0;
		while (tempStudent->cursesID[index] != '\0') {
			for (int i = 0; i < 5; i++) {
				curse[i] = tempStudent->cursesID[index + i];
			}
			if (strcmp(curse, curseId) == 0) {
				numberOfStudent++;
				int power = 1;
				for (int i = 0; i < 5; i++) {
					printf("!!!!!!!!!!!!!!!  %s %s %s %s\n", tempStudent->name, tempStudent->grades, tempStudent->cursesID, curse);
					if (tempStudent->grades[index + 4 - i] != '.') {
						grade = grade + (tempStudent->grades[index + 4 - i] - '0') * power;
						power = power * 10;
						printf("!!!!!!!@@@@@@@@####### grade - %d\n", grade);
					}

				}
			}
			index = index + 5;
		}
		tempStudent = tempStudent->next;
	}
	if (numberOfStudent != 0) {
		printf("%s %s, %d\n", curseId, curseName, grade);
	}
	else {
		printf("Class \"%s %S\" has no students.\n", curseId, curseName);
	}
}

/******************
* Function Name: numOfStudents
* Input: Student* firstStudent, char* curseName, char* curseId
* Output: NONE
* Function Operation: print the students number
******************/
void numOfStudents(Student* firstStudent, char* curseName, char* curseId) {
	Student* tempStudent = firstStudent->next;
	int numberOfStudent = 0;
	while (tempStudent != NULL) {
		char curse[6];
		curse[5] = '\0';
		int index = 0;
		while (tempStudent->cursesID[index] != '\0') {
			for (int i = 0; i < 5; i++) {
				curse[i] = tempStudent->cursesID[index + i];
			}
			if (strcmp(curse, curseId) == 0) {
				numberOfStudent++;
			}
			index = index + 5;
		}
		tempStudent = tempStudent->next;
	}
	if (numberOfStudent != 0) {
		printf("%s %s, %d\n", curseId, curseName, numberOfStudent);
	}
	else {
		printf("Class \"%s %S\" has no students.\n", curseId, curseName);
	}
}


/******************
* Function Name: CursesAggregation
* Input: Student* firstStudent, Curses* allCurses, int numOfCurses
* Output: NONE
* Function Operation: calculate the grade of every curse by user choise
******************/
void CursesAggregation(Student* firstStudent, Curses* allCurses, int numOfCurses) {
	printf("Please select the aggregation method :\n");
	printf("\ta. Average Grade.\n");
	printf("\tb. Maximal Grade.\n");
	printf("\tc. Minimal Grade.\n");
	printf("\td. Sum.\n");
	printf("\te. Count.\n");
	printf("\t0. Return to the main menu\n");
	while (1) {
		char userChoise;
		scanf(" %c", &userChoise);
		char curseName[31];
		char curseId[6];
		for (int i = 0;i < numOfCurses;i++) {
			for (int j = 0; j < strLength(allCurses[i].curseName, 0);j++) {
				curseName[j] = allCurses[i].curseName[j];
				curseName[j + 1] = '\0';
			}
			for (int j = 0; j < 5;j++) {
				curseId[j] = allCurses[i].curseID[j];
				curseId[j + 1] = '\0';
			}
			if (userChoise == 'a') {
				averageGrade(firstStudent, curseName, curseId);
			}
			if (userChoise == 'b') {
				maxGrade(firstStudent, curseName, curseId);
			}
			if (userChoise == 'c') {
				minGrade(firstStudent, curseName, curseId);
			}
			if (userChoise == 'd') {
				sumGrade(firstStudent, curseName, curseId);
			}
			if (userChoise == 'e') {
				numOfStudents(firstStudent, curseName, curseId);
			}
			if (userChoise == '0') {
				return;
			}
		}
	}
}


/******************
* Function Name: freeStudent
* Input: Student* firstStudent
* Output: NONE
* Function Operation: calculate the grade of every curse by user choise
******************/
void freeStudent(Student* firstStudent) {
	if (firstStudent == NULL) {
		return;
	}
	freeStudent(firstStudent->next);
	free(firstStudent->cursesID);
	free(firstStudent->grades);
	free(firstStudent->name);
	free(firstStudent);
}
