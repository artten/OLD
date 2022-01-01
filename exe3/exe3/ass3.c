#include "ass3.h"
#include "stdio.h"

int count = 0;//for printAllCombinations function

int sizeOfArry(char* str) {
	if (str[0] == '\0')
	{
		return 0;
	}
	return 1 + sizeOfArry(str + 1);

}

void isPalindrome(char str[], int len) {
	int size = sizeOfArry(str);
	if (size / 2 == len) {
		printf("The reverse of %s is also %s.\n", str, str);
	}
	else {
		if (str[size - len] == str[len - 1]) {
			isPalindrome(str, len - 1);
		}
		else {
			printf("The reverse of %s is not %s.\n", str, str);
		}
	}

}

void copyString(char original[], char copy_str[], int copy_size) {
	if (copy_size == -1)
		return;
	original[copy_size - 1] = copy_str[copy_size - 1];
	copyString(original, copy_str, copy_size - 1);
}

int countAllPossibilities(char pattern[], int len, int size) {
	int count = 1;
	if (size == len)
	{
		return 1;
	}
	if (pattern[len] == '?')
	{
		return countAllPossibilities(pattern, ++len, size) * 3;
	}
	else
	{
		return countAllPossibilities(pattern, ++len, size);
	}
}

void printAllCombinations(char pattern[], int len) {
	if (len == 0) {
		printf("%s\n", pattern);
		++count;
		return;
	}
	int str_size = sizeOfArry(pattern);
	int index = str_size - len;
	if (pattern[index] == '?') {
		char* copy_pattern = pattern;
		copyString(pattern, copy_pattern, str_size);
		*(copy_pattern + index) = '0';
		printAllCombinations(pattern, len - 1);
		*(copy_pattern + index) = '1';
		printAllCombinations(pattern, len - 1);
		*(copy_pattern + index) = '2';
		printAllCombinations(pattern, len - 1);
		*(copy_pattern + index) = '?';
	}
	else
	{
		printAllCombinations(pattern, len - 1);
	}
	if (str_size == len) {
		int str_size = sizeOfArry(pattern);
		int final_count = countAllPossibilities(pattern, 0, str_size);
		if (final_count == count) {
			printf("Number of combinations is: %d\n", count);
		}
		return;
	}
}

float powRecHelper(float firsrtNum, float secondNum) {
	if (secondNum == 0)
	{
		return 1;
	}
	else
	{
		if(secondNum >= 0){
			return powRecHelper(firsrtNum, secondNum - 1) * (float)firsrtNum;
		}
		else{
			return powRecHelper((float)(1/ (float)firsrtNum), (0 - secondNum) - 1) * (float)(1 / (float)firsrtNum);
		}
	}
}

void powRec(long int firsrtNum, long int secondNum) {
	if (firsrtNum == 0 && secondNum < 0) {
		printf("The result is nan.\n");
		return;
	}
	float result = powRecHelper(firsrtNum, secondNum);
	printf("The result is %f.\n", result);

}

int isDivisibleBy3Helper(long long n) {
	if (n == 0) {
		return 3;
	}
	else
	{
		int lastDigit = n % 10;
		int result = 0;
		switch (lastDigit)
		{
		case 1:
			switch (isDivisibleBy3Helper(n / 10))
			{
			case 1:
				return 2;
				break;
			case 2:
				return 3;
				break;
			case 3:
				return 1;
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (isDivisibleBy3Helper(n / 10))
			{
			case 1:
				return 3;
				break;
			case 2:
				return 1;
				break;
			case 3:
				return 2;
				break;
			default:
				break;
			}
			break;
		case 3:
			switch (isDivisibleBy3Helper(n / 10))
			{
			case 1:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 3;
				break;
			default:
				break;
			}
			break;
		default:
			return 0;
			break;
		}
	}
}

void isDivisibleBy3(long long n) {
	if (isDivisibleBy3Helper(n) == 3)
	{
		printf("The number %llu is divisible by 3.\n", n);
	}
	else
	{
		printf("The number %llu is not divisible by 3.\n", n);
	}

}

void gcd(long int n1, long int n2) {
	if (n2 == 0 ) {
		if (n1 < 0) {
			printf("GCD=%ld\n", -n1);
			return;
		}
		printf("GCD=%ld\n", n1);
		return;
	}
	if (n1 == 0) {
		if (n2 < 0) {
			printf("GCD=%ld\n", -n2);
			return;
		}
		printf("GCD=%ld\n", n2);
		return;
	}
	int unsignedN1 = n1;
	int unsignedN2 = n2;
	if (n1 < 0) {
		unsignedN1 = -1 * n1;
	}
	if (n2 < 0) {
		unsignedN2 = -1 * n2;
	}

	if (unsignedN1 > unsignedN2) {
		if (unsignedN1 == n1 && n2 == unsignedN2) {
			long int diveded = n1 / n2;
			long int multiplication = n2 * diveded;
			long int sub = (unsignedN1 - multiplication);
			printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n", n2, diveded, sub, n1, n1, n2);
			gcd(n2, sub);
			return;
		}
		else if (unsignedN1 != n1 && n2 == unsignedN2) {
			long int diveded = n1 / n2;
			long int multiplication = n2 * diveded;
			long int sub = (n1 - multiplication);
			printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n", n2, diveded, sub, n1, n1, n2);
			gcd(n2, sub);
			return;
		}
		else if (unsignedN1 == n1 && n2 != unsignedN2) {
			long int diveded = n1 / n2;
			long int multiplication = n2 * diveded;
			long int sub = (n1 - multiplication);
			printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n", n2, diveded, sub, n1, n1, n2);
			gcd(n2, sub);
			return;
		}
		else if (unsignedN1 != n1 && n2 != unsignedN2) {
			long int diveded = n1 / n2;
			long int multiplication = n2 * diveded;
			long int sub = (n1 - multiplication);
			printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n", n2, diveded, sub, n1, n1, n2);
			gcd(n2, sub);
			return;
		}

	}
	else {
		long int diveded = n1 / n2;
		long int multiplication = n1 * diveded;
		long int sub = (unsignedN2 - multiplication);
		printf("%ld*0+%ld=%ld(a=%ld,b=%ld)\n", n2, n1, n1, n1, n2);
		gcd(n2, n1);
		return;
	}

}

int countDigitHelper(long long n, int d) {
	if (n == 0)
	{
		return 0;
	}
	else
	{
		if (n % 10 == d)
		{
			return 1 + countDigitHelper(n / 10, d);
		}
		else
		{
			return  countDigitHelper(n / 10, d);
		}
	}
}

void countDigit(long long n, int d) {
	int count = countDigitHelper(n, d);
	printf("%llu has %d times %d.\n", n, count, d);

}

void isPalindromeIter(char str[], int len) {
	for (int i = 0;i <= (len / 2); i++) {
		if (str[i] != str[len - 1 - i]) {
			printf("The reverse of %s is not %s.\n", str, str);
			return;
		}
	}
	printf("The reverse of %s is also %s.\n", str, str);
}

int longLongNumSize(long long num) {
	int count = 0;
	while (num != 0) {
		count++;
		num = num / 10;
	}
	return count;
}

void IsDividedBy3Iter(long long num) {
	long long num_copy = num;
	while (1) {
		long long sum_num = 0;
		long long num_size = longLongNumSize(num_copy);
		for (long long i = 0; i <= num_size; i++) {
			sum_num = sum_num + num_copy % 10;
			num_copy = num_copy / 10;
		}
		if (sum_num == 0||sum_num == 3 || sum_num == 6 || sum_num == 9)
		{
			printf("The number %llu is divisible by 3.\n", num);
			break;
		}
		else if (sum_num <= 10) {
			printf("The number %llu is not divisible by 3.\n", num);
			break;
		}

		num_copy = sum_num;
	}


}

void towerOfHanoi(int numDisks, char fromRod, char toRod, char auxRod) {
	if (numDisks == 1 || numDisks == 0) {
		printf("Move disk 1 from rod %c to rod %c.\n", fromRod, toRod);
		return;
	}
	towerOfHanoi(numDisks - 1, fromRod, auxRod, toRod);
	printf("Move disk %d from rod %c to rod %c.\n", numDisks, fromRod, toRod);
	towerOfHanoi(numDisks - 1, auxRod, toRod, fromRod);
}

//int main() {
	//isPalindrome("p454pp", 5);
	//char pattern[] = "???";
	//printAllCombinations(pattern, 3);
	//powRec((long int)-3, (long int)3);
	//isDivisibleBy3(123232323232);
	//countDigit((long long)123432141,1);
	//gcd( 105, 51);
	//isPalindromeIter("p54665p", 5);
	//isDividedBy3Iter(123232323231);
	//int n = 2; // Number of disks
	//towerOfHanoi(2, 'A', 'C', 'B'); // A, B and C are the names of the rods
	//return 0;
	//towerOfHanoi(2, 'A', 'C', 'B');
//}
