/***********
* Artiom Divak
* 319339198
* 01
* ass0SIZE*SIZE
***********/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

/******************
* Function Name: sizeOfStr
* Input: char str (string)
* Output:return the number of char insidfe the string
* Function Operation: the fun doing while loop till it incounters '/0'
******************/
int sizeOfStr(char str[]) {
	int count = 0;
	while (str[count] != 0) {
		count++;
	}
	return count;
}

/******************
* Function Name: spaceChar
* Input: char  letter (the letter to check)
* Output:return not 0  if the letter should be replaced with spaces and returns 0 if the letter shold not be replaced with spaces
* Function Operation: checking if the letter shold be replaced with spaces and the number of spaces
******************/
int spaceChar(char letter) {
	if (letter - 'a' < SIZE * SIZE && letter - 'a' >= 0) {
		return letter - 'a' + 1;
	}
	return 0;
}

/******************
* Function Name: checkIfStrValid
* Input:int rowLength(size of board row),char str[](str to check)
* Output:return 0 if str is not valid return 1 if str is valid
* Function Operation: checking if the str is valid
******************/
int checkIfStrValid(int rowLength, char str[]) {
	int strLength = sizeOfStr(str);
	if (rowLength * rowLength + rowLength/*to add all '/'*/ < strLength) {
		return 0;
	}
	int countChars = 0;
	int countSlash = 0;
	for (int i = 0; i < strLength;i++) {
		if (str[i] != '/') {
			if (str[i] >= '1' && str[i] <= '9') {
				countChars++;
			}
			if (spaceChar(str[i]) > 0) {
				countChars = countChars + spaceChar(str[i]);
			}
			if (spaceChar(str[i]) == 0 && (str[i] < '1' || str[i] > '9')) {
				countChars++;
			}
		}
		else {
			countSlash++;
			if (countChars > rowLength) {
				return 0;
			}
			countChars = 0;
		}
	}
	if (countSlash != rowLength - 1) {
		return 0;
	}
	return 1;

}

/******************
* Function Name: buildBoard
* Input:char board[][9], char str[]
* Output:void (fill the board with str data )
* Function Operation:fill the board wit str data
******************/
void buildBoard(char board[][9], char str[]) {
	int strSize = sizeOfStr(str);
	int boardRow = 0;
	int boardColumn = 0;
	for (int i = 0; i < strSize + 1;i++) {
		if (str[i] != '/') {
			if (boardRow == SIZE * SIZE - 1 && str[i] == 0) {
				if (boardColumn < (SIZE * SIZE)) {
					int addSpaces = SIZE * SIZE - boardColumn;
					for (int i = 0;i < addSpaces;i++) {
						board[boardRow][boardColumn] = ' ';
						boardColumn++;
					}
				}
				break;
			}
			if (str[i] >= 'a' && str[i] <= 'z') {
				if (spaceChar(str[i])) {
					for (int j = 0; j < spaceChar(str[i]);j++) {
						board[boardRow][boardColumn] = ' ';
						boardColumn++;
					}
				}
				else {
					board[boardRow][boardColumn] = str[i];
					boardColumn++;
				}
			}
			else {
				board[boardRow][boardColumn] = str[i];
				boardColumn++;
			}
		}
		else {
			if (boardColumn < (SIZE * SIZE)) {
				int addSpaces = SIZE * SIZE - boardColumn;
				for (int i = 0;i < addSpaces;i++) {
					board[boardRow][boardColumn] = ' ';
					boardColumn++;
				}
			}
			boardColumn = 0;
			boardRow++;
		}
	}
}

/******************
* Function Name: createBoard
* Input:char board[][] (array of chars that contains junk data ), char str[] (contains a real(or not) board of sudoku)
* Output:void (fill the board with str data )
* Function Operation:fill the board with str data if vlaid str given
******************/
void createBoard(char board[][9], char str[]) {//dont forget to get it offff!!!!!!!!!!!!!!

	if (checkIfStrValid(SIZE * SIZE, str) == 0) {
		printf("Error\n");
		return;
	}
	buildBoard(board, str);
}

/******************
* Function Name: printBoard
* Input:char board[][] (filled board with data)
* Output:void (prints the board)
* Function Operation:prints the given board
*										ex: ___ ___ ___
*										   |_a_|_1_|___|
*										   |_@_|_2_|_0_|
*										   |_3_|_#_|___|
******************/
void printBoard(char board[][4]) {//dont forget to get it offff!!!!!!!!!!!!!!
	int rowSize = SIZE * SIZE;
	for (int j = 0;j < rowSize;j++) {//print the top part with _ character once
		printf(" ___");
	}
	printf("\n");//starts a new line
	for (int i = 0; i < rowSize; i++)
	{
		printf("|");
		for (int j = 0;j < rowSize;j++) {//print the top part with _
			if (board[i][j] != ' ') {
				printf("_%c_|", board[i][j]);
			}
			else
			{
				printf("___|");
			}

		}
		printf("\n");//starts drowing next row
	}
}

/******************
* Function Name: printBoard
* Input:char board[][] (filled board with data)
* Output:void (prints the board)
* Function Operation:prints the given board
*										ex: ___ ___ ___
*										   |_a_|_1_|___|
*										   |_@_|_2_|_0_|
*										   |_3_|_#_|___|
******************/
void printbBoard(char board[][9]) {//dont forget to get it offff!!!!!!!!!!!!!!
	int rowSize = SIZE * SIZE;
	//for (int j = 0;j < rowSize;j++) {//print the top part with _ character once
	//	printf(" ___");
	//}
	printf("\n");//starts a new line
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0;j < SIZE;j++) {//print the top part with _
			for (int k = 0;k < SIZE;k++) {//print the top part with _
				printf("%c",board[i][j*SIZE+k]);
			}
			if (j != SIZE - 1) {
				printf(" | ");
			}
			else {
				printf("\n");
			}

		}
	}
}

/******************
* Function Name: containsStrings
* Input:char str1[], char str2[]
* Output:returns 0 if str1 not contains str2
* Function Operation: check if str2 is smaller than str 1 and then compare char by char
******************/
int containsStrings(char str1[], char str2[]) {
	int str1Size = sizeOfStr(str1);
	int str2Size = sizeOfStr(str2);
	if (str2Size > str1Size) {
		return 0;
	}
	else {
		for (int i = 0; i < str2Size; i++) {
			if (str1[i] != str2[i]) {
				return 0;
			}
		}
	}
	return 1;
}

/******************
* Function Name: fistComma
* Input:char str[](move array)
* Output:returns 0 if str do not contains , else return the location of the first comma
* Function Operation: for loop in strand serch for ,
******************/
int firstComma(char str[]) {
	int strSize = sizeOfStr(str);
	for (int i = 0; i < strSize;i++) {
		if (str[i] == ',') {
			return i;
		}
	};
	return 0;
}

/******************
* Function Name: commasInStr
* Input:char str[](move array)
* Output:returns 0 if str do not contains , or there is comma after comma(wrong) else retuen numbers if ,
* Function Operation: finds the first comma and start checking how much comass there is
******************/

int commasInStr(char str[]) {
	int strSize = sizeOfStr(str);
	int count = 0;
	int i = firstComma(str);
	if (i == 0) {
		return 0;
	}
	count = 0;
	for (; i < strSize - 1;i = i + 2) {
		if (str[i] != ',' || str[i + 1] == ',') {
			return 0;
		}
		count++;
	}
	return count;
}

/******************
* Function Name: checkMove
* Input:char move (string that contains user move)
* Output:int returns 1 if the command should be replaceAll ,returns 2 if change,returns 3 if add ,returns SIZE*SIZE if delete ,returns 0 if not valid command
* Function Operation: running a for loop and compare the first word of move
******************/
int checkMove(char move[]) {
	char replaceAll[] = "replaceAll";
	char change[] = "change";
	char add[] = "add";
	char delete[] = "delete";
	int comass[] = { 2,3,3,2 };
	if (containsStrings(move, replaceAll)) {
		if (commasInStr(move) == comass[0]) {
			return 1;
		}
	}
	if (containsStrings(move, change)) {
		if (commasInStr(move) == comass[1]) {
			return 2;
		}
	}
	if (containsStrings(move, add)) {
		if (commasInStr(move) == comass[2]) {
			return 3;
		}
	}
	if (containsStrings(move, delete)) {
		if (commasInStr(move) == comass[3]) {
			return 4;
		}
	}

	return 0;
}

/******************
* Function Name: replaceAllMove
* Input:char board[], char move[]
* Output:int 1 if everything is right else output is 0
* Function Operation:find the char1(toBeReplace) and char2(toReplaceWith) and vlaidate them and then doing loop in board to replace all to be replace
******************/
int replaceAllMove(char board[][4], char move[]) {
	int first = firstComma(move);
	char toBeReplace = move[first + 1];
	char toReplaceWith = move[first + 3];
	if (toBeReplace == ' ' || toBeReplace == '/' || spaceChar(toBeReplace) || spaceChar(toReplaceWith) || toReplaceWith == '/') {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < SIZE * SIZE;i++) {
		for (int j = 0;j < SIZE * SIZE;j++) {
			if (board[i][j] == toBeReplace) {
				board[i][j] = toReplaceWith;
				count++;
			}
		}
	}
	if (count == 0) {
		return 0;
	}
	return 1;
}
/******************
* Function Name: changeMove
* Input:char char board[], char move[]
* Output:int 1 if everything is right else output is 0
* Function Operation:find the row,col and char(replaceWith) inside move[]  and vlaidate them then replace the data inside board with char
******************/
int changeMove(char board[][4], char move[]) {

	int first = firstComma(move);
	int row = move[first + 1] - '0';
	int col = move[first + 3] - '0';
	char replaceWith = move[first + 5];
	if (replaceWith == ' ' || replaceWith == '\n' || row >= SIZE * SIZE || col >= SIZE * SIZE || board[row][col] == ' ') {
		return 0;
	}
	board[row][col] = replaceWith;
	return 1;
}
/******************
* Function Name: addMove
* Input:char board[], char move[]
* Output:int 1 if everything is right else output is 0
* Function Operation: find the row,col and char(replaceWith) inside move[]  and vlaidate them then replace the data inside board with char
******************/
int addMove(char board[][4], char move[]) {
	int first = firstComma(move);
	int row = move[first + 1] - '0';
	int col = move[first + 3] - '0';
	char replaceWith = move[first + 5];
	if (replaceWith == ' ' || replaceWith == '\n' || row >= SIZE * SIZE || col >= SIZE * SIZE || board[row][col] != ' ') {
		return 0;
	}
	board[row][col] = replaceWith;
	return 1;
}
/******************
* Function Name: deleteMove
* Input:char board[], char move[]
* Output:int 1 if everything is right else output is 0
* Function Operation: find the row,col and char(replaceWith) inside move[]  and vlaidate them then replace the data inside board with space
******************/
int deleteMove(char board[][4], char move[]) {
	int first = firstComma(move);
	int row = move[first + 1] - '0';
	int col = move[first + 3] - '0';

	if (row >= SIZE * SIZE || col >= SIZE * SIZE || board[row][col] == ' ') {

		return 0;
	}
	board[row][col] = ' ';
	return 1;
}

/******************
* Function Name: makeMove
* Input:char board[][] (array of chars that contains the board data ), char move[] (contains what kind of move should be done)
* Output:void (fill the board with str data ) if command not valid prints error
* Function Operation:if the char move is a valid command do the change inside board if not prints error
******************/
void makeMove(char board[][4], char move[]) {//dont forget to change
	int moveNumber = checkMove(move);
	if (moveNumber == 1) {
		if (replaceAllMove(board, move) == 0) {
			printf("Error\n");
			return;
		}
		return;
	}
	if (moveNumber == 2) {
		if (changeMove(board, move) == 0) {
			printf("Error\n");
			return;
		}
		return;
	}
	if (moveNumber == 3) {
		if (addMove(board, move) == 0) {
			printf("Error\n");
			return;
		}
		return;
	}
	if (moveNumber == 4) {
		if (deleteMove(board, move) == 0) {
			printf("Error\n");
			return;
		}
		return;
	}
	printf("Error\n");
	return;

}

/******************
* Function Name: initCharArray
* Input:char * str,int size
* Output:void(init char array)
* Function Operation: do a for loop and puts 0
******************/
void initCharArray(char* str, int size) {
	for (int i = 0;i < size;i++) {
		*(str + 1) = 0;
	}

}

/******************
* Function Name: initCharArray
* Input:char * str,int size
* Output:int return 1 if no number appears twice or more else returns 0
* Function Operation: do a for loop and check the data inside str
******************/
int noSameNumberInArray(char* str, int size) {
	int checkArray[] = { 0,1,2,3,SIZE * SIZE,5,6,7,8,9 };
	for (int i = 0;i < size;i++) {
		if (str[i] != ' ') {
			int toCheck = str[i] - '0';
			if (checkArray[toCheck] == 0) {
				return 0;
			}
			else {
				checkArray[toCheck] = 0;
			}
		}
	}
	return 1;

}

/******************
* Function Name: onlyNumbersAndSpaces
* Input:char * str,int size
* Output:int return 1 if only number and spaces appears else returns 0
* Function Operation: do a for loop and check the data inside str
******************/
int onlyNumbersAndSpaces(char* str, int size) {
	for (int i = 0;i < size;i++) {
		if (str[i] != ' ' && (str[i] > '0' + SIZE * SIZE || str[i] < '1')) {
			return 0;
		}
	}
	return 1;

}

/******************
* Function Name: rowsCheck
* Input:char board[][]
* Output:int if the bord rows is valid return 1 else return 0
* Function Operation:check the rows if they are valid(validate them by the rules of sudoku)
******************/
int rowsCheck(char board[][4]) {//dont forget to change !!!!
	int rowSize = SIZE * SIZE;
	char rowArray[9];
	for (int i = 0;i < rowSize;i++) {
		initCharArray(rowArray, 9);
		for (int j = 0; j < rowSize;j++) {
			rowArray[j] = board[i][j];
		}
		if (noSameNumberInArray(rowArray, rowSize) == 0 || onlyNumbersAndSpaces(rowArray, rowSize) == 0) {
			return 0;
		}
	}
	return 1;
}

/******************
* Function Name: colCheck
* Input:char board[][]
* Output:int if the board col is valid return 1 else return 0
* Function Operation:check the columns if they are valid(validate them by the rules of sudoku)
******************/
int colCheck(char board[][4]) {//dont forget to change !!!!
	int colSize = SIZE * SIZE;
	char colArray[9];
	for (int i = 0;i < colSize;i++) {
		initCharArray(colArray, 9);
		for (int j = 0; j < colSize;j++) {
			colArray[j] = board[j][i];
		}
		if (noSameNumberInArray(colArray, colSize) == 0 || onlyNumbersAndSpaces(colArray, colSize) == 0) {
			return 0;
		}
	}
	return 1;
}

/******************
* Function Name: rowsCheck
* Input:char board[][]
* Output:int if the bord rows is valid return 1 else return 0
* Function Operation:check the rows if they are valid(validate them by the rules of sudoku)
******************/
int squreCheck(char board[][4]) {//dont forget to change !!!!
	int squreSize = SIZE;
	char squreArray[9];
	for (int i = 0; i < squreSize;i++) {
		for (int j = 0; j < squreSize; j++) {
			initCharArray(squreArray, 9);
			for (int k = 0; k < squreSize; k++) {
				for (int l = 0; l < squreSize; l++) {
					squreArray[k + l] = board[i * squreSize + k][j * squreSize + l];
				}
			}
			if (noSameNumberInArray(squreArray, squreSize) == 0 || onlyNumbersAndSpaces(squreArray, squreSize) == 0) {
				return 0;
			}
		}
	}
	return 1;
}

/******************
* Function Name: isSameBoard
* Input:char board1[][SIZE*SIZE], char board2[][SIZE*SIZE]
* Output:int returns 1 if the board are the same else returns 0
* Function Operation: do a for loop to check every row and column and compare them in board1 and board2
******************/
int isSameBoard(char board1[][4], char board2[][4]) {
	int rowSize = SIZE * SIZE;
	for (int i = 0; i < rowSize;i++) {
		for (int j = 0; j < rowSize; j++) {
			if (board1[i][j] != board2[i][j]) {
				printf("Found inequality on row %d col %d.\n", i, j);
				return 0;
			}
		}
	}
	return 1;
}

/******************
* Function Name: sumRow
* Input:char board[][SIZE*SIZE], int row
* Output:int returns the result of the row in the board
* Function Operation:returns the result of the row in the board
******************/
int sumRow(char board[][4], int row) {
	int result = 0;
	for (int i = 0; i < SIZE * SIZE;i++) {
		if (board[row][i] != ' ')
			result = result + board[row][i] - '0';
	}
	return result;
}

/******************
* Function Name: sumCol
* Input:char board[][SIZE*SIZE], int col
* Output:int returns the result of the col in the board
* Function Operation:returns the result of the row in the board
******************/
int sumCol(char board[][4], int col) {
	int result = 0;
	for (int i = 0; i < SIZE * SIZE;i++) {
		if (board[i][col] != ' ')
			result = result + board[i][col] - '0';
	}
	return result;
}

/******************
* Function Name: sumSqure
* Input:char board[][SIZE*SIZE], int index
* Output:int returns the result of the col in the board
* Function Operation:returns the result of the row in the board
******************/
int sumSqure(char board[][4], int col, int row) {
	int result = 0;
	int startRow = row / SIZE;
	int startCol = col / SIZE;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[SIZE * startRow + i][SIZE * startCol + j] != ' ') {
				result = result + board[SIZE * startRow + i][SIZE * startCol + j] - '0';
			}
		}
	}
	return result;
}

/******************
* Function Name: checkPosibleAnswers
* Input:int answerStr[9],char board [][SIZE*SIZE]
* Output:int returns 1 if the board can be field else returns 0
* Function Operation: do a for loop and comper the sum of thwe rows and columns
******************/
int checkPosibleAnswers(int answerStr[9], char board[][4]) {
	for (int i = 0; i < SIZE * SIZE;i++) {
		if (answerStr[i] != -1) {
			if (sumCol(board, answerStr[i]) != sumRow(board, i) || sumSqure(board, answerStr[i], i) != sumRow(board, i)) {
				return 0;
			}
		}
	}
	return 1;
}

/******************
* Function Name: testBoard
* Input:char board[][]
* Output:int if the bord is valid return 1 else return 0
* Function Operation:check the rows the columns and squre if they are valid(validate them by the rules of sudoku)
******************/
int testBoard(char board[][4]) {//dont forget to change !!!!

	if (rowsCheck(board) && colCheck(board) && squreCheck(board)) {
		return 1;
	}
	return 0;
}

/******************
* Function Name: completeBoard
* Input:char board1[][SIZE*SIZE], char board2[][SIZE*SIZE]
* Output:int returns 1 if the board can be filed and file it else return 0 and do not touch the board
* Function Operation: int returns 1 if the board can be filed and file it else return 0 and do not touch the board
******************/
int completeBoard(char board[][4]) {
	if (testBoard(board)) {
		int count = 0;
		int toAnswer[9] = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
		for (int i = 0; i < SIZE * SIZE;i++) {
			count = 0;
			for (int j = 0; j < SIZE * SIZE;j++) {
				if (board[i][j] == ' ') {
					count++;
					toAnswer[i] = j;
				}
			}
			if (count > 1) {
				printf("Error\n");
				return 0;
			}
		}
		if (checkPosibleAnswers(toAnswer, board)) {
			for (int i = 0; i < SIZE * SIZE;i++) {
				int index = toAnswer[i];
				int rowSize = SIZE * SIZE;
				if ((rowSize * (rowSize + 1)) / 2 - sumRow(board, i) + '0' != '0') {
					board[i][index] = (rowSize * (rowSize + 1)) / 2 - sumRow(board, i) + '0';
				}

			}
			return 1;
		}
	}
	printf("Error\n");
	return 0;
}

void f1() {
	char board[9][9];
	char str[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679";
	createBoard(board, str);
	printbBoard(board);
}



int main() {
	//printf("%d", spaceChar(2,'f'));
	//int chapo[][7] = {0};
	//printf("%d", sizeof(chapo)/sizeof(chapo[0][0]));
	//for (int i = 0; i < 3; i++) {
	//	for(int j =0 ; j< 7;j++)
	//		printf("%d = chapo[%d][%d]\n", chapo[i][j],i,j);
	//}
	char str[] = "123/1@3/123";
	
//	char str1[] = "i/123SIZE*SIZE56789/12aSIZE*SIZE56789/123b6789/123SIZE*SIZEc89/123SIZE*SIZE5d/123SIZE*SIZE5678*//A23SIZE*SIZE56789";
//	char board[SIZE*SIZE][SIZE*SIZE];
	//createBoard(board, str);
	//printBoard(board);

	//printf("%d\n", strlen(str));
	//for (int i = 0; i <= strlen(str);i++) {
	//	printf("%d\n", str[i]);
	//}
	//printf("%d" ,checkIfStrValid(SIZE*SIZE, str, sizeof(str)));
	//printBoard(board);
	//char str[9] = "11.2.3.SIZE*SIZE";
	//char * token = strtok(str, ".");
	//char* token2 = strtok(str, ".");
	//printf("%s\n", (token2));
	//printf("%d\n",sizeOfStr(token));
	//printf("%s\n",(token+sizeOfStr(token)+1));
//	char* str = "change,0,0,*";
//	char board1[1][1] = {'@'};
	//printf("c====%c\n", board1[0][0]);
//	makeMove(board1, str);
//	printBoard(board1);

	//printf("%d",checkCorrectStrMove(str));
	//test(str);
	//char str[2][3] = { { '2','3','a'},{ '2','3','a'  } };
	//test(str);
	char board1[4][4] = { {'1','3',' ','4'},{'4','3','2',' '},{'3',' ','4','2'},{' ','4','1','3' } };
	//char board2[SIZE*SIZE][SIZE*SIZE] = { {'1','1','5','9'},{'2',' ','6','8'},{'SIZE*SIZE','@',' ','3'},{'3','7',' ','2' } };
	//printBoard(board1);
	f1();
	//printf("%d\n",completeBoard(board1));
	//(board1);
	//char move[] = "delete,1,0";
	//makeMove(board,move);
	//printBoard(board);
	//char board[9][9];
	//char str[] = "12a3SIZE*SIZE5679/12a3SIZE*SIZE5679/12a3SIZE*SIZE5679/12a3SIZE*SIZE5679/12a3SIZE*SIZE5678/12a3SIZE*SIZE5978/12a3SIZE*SIZE5879/12a385679/18a3SIZE*SIZE5679";
	//createBoard(board, str);
	//printBoard(board);
}
