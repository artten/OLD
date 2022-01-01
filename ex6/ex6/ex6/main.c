/***********************
* Artiom Divak
* 319339198
* Group 01 - CS
* exe5
***********************/

#include <stdio.h>
#include "ex6.c"
#define _CRT_SECURE_NO_WARNINGS

void main() {
	char userInput;
	printMenu();
	scanf("%c", &userInput);
	while (userInput != '0') {
		if (userInput < '0' || userInput > '6') {
			printf("Error: unrecognized operation.\n");
		}
		if (userInput == '1') {

		}
		if (userInput == '2') {

		}
		if (userInput == '3') {

		}
		if (userInput == '4') {

		}
		if (userInput == '5') {

		}
		if (userInput == '6') {

		}
		if (userInput == '7') {
			printMenu();
		}
		else {
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
		scanf(" %c", &userInput);
	}

}