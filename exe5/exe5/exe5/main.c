/***********************
* Artiom Divak
* 319339198
* Group 01 - CS
* exe5
***********************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ex5.h"

void main() {
	char userInput = 1;
	Curses allCurses[5];
	int numOfCurses = 0;
	Student* firstStudent = (Student*)calloc(1, sizeof(Student));
	if (firstStudent == NULL) {
		return;
	}
	firstStudent->next = NULL;
	int numberOfStudents = 0;
	printf("Please select an operation:\n\t0. Exit.\n\t1. Insert or update a class.\n\t2. Insert or update a student.");
	printf("\n\t3. Remove a student from classes.\n\t4. Print a class.");
	printf("\n\t5. Print all classes with their computed scores.\n\t6. Print the menu\n");
	scanf("%c", &userInput);
	while (userInput != '0') {
		if (userInput < '1' || userInput > '6') {
			printf("Error: unrecognized operation %c.\n");
			continue;
		}
		if (userInput == '1') {
			if (numOfCurses != 4) {
				newOrUpdateCurse(allCurses, &numOfCurses);
			}
			else {
				printf("Unfortunately, there is no room for more classes.");
			}

		}
		if (userInput == '2') {
			if (newOrUpdateStudent(firstStudent, allCurses, numOfCurses)) {
			}
			else {
				printf("Error: invalid name, class number or grade.\n");
			}
		}
		if (userInput == '3') {
			removeStudent(firstStudent, allCurses, numOfCurses);
		}
		if (userInput == '4') {
			getAllCurseStudents(firstStudent, allCurses, numOfCurses);
		}
		if (userInput == '5') {
			CursesAggregation(firstStudent, allCurses, numOfCurses);
		}
		if (userInput == '6') {
			printf("Please select an operation:\n\t0. Exit.\n\t1. Insert or update a class.\n\t2. Insert or update a student.");
			printf("\n\t3. Remove a student from classes.\n\t4. Print a class.");
			printf("\n\t5. Print all classes with their computed scores.\n\t6. Print the menu\n");
		}
		printf("Select the next operation (insert 6 for the entire menu):\n");
		scanf(" %c", &userInput);
		if (userInput == '0') {
			freeStudent((Student*)firstStudent->next);
			free(firstStudent);
		}
	}

}