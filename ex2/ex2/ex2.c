#include <stdio.h>
int main()
{
	char user_input;
	printf("Choose an option:\n1. Rhombus\n2. Base 20 to Decimal\n3. Base to Decimal\n4. Pow2\n5. Different bits\n6. Add\n7. Multiply\n0. Exit\n");
	scanf("%c", &user_input);
	while (user_input != '0') {
		switch (user_input)
		{
		case '1':{
			//Rhombus
			int rhombus_side;
			printf("Enter the sides length:\n");
			scanf("%d", &rhombus_side);

			//total_rhombus_length will contain tje total line needed to be print
			int total_rhombus_length = rhombus_side * 2 + 1;//+1 including the center
			int rhombus_width = rhombus_side * 2 + 1;//+1 include the center 

			//spaces will contain the number of spaces in every line
			int spaces = (rhombus_side - 1) * 2;
			int line_center = rhombus_width / 2;

			for (int i = 0;i < total_rhombus_length;i++) {
				//top side
				if (i < (int)total_rhombus_length / 2) {
					for (int j = 0;j < rhombus_width;j++) {
						//print center
						if (j == line_center) {
							printf("*");
						}
						//left side
						else if (j < line_center) {
							if (j == line_center - i - 1) {// line_center - i - 1 = location of '/'
								printf("/");
							}
							else
							{
								printf(" ");
							}
						}
						//right side
						else if (j > line_center) {
							if (j == line_center + i + 1) {// line_center + i + 1 = location of '\'
								printf("\\");
							}
							else if (j < line_center + i + 1)
							{
								printf(" ");
							}
						}
					}
				}
				//center
				if (i == (int)total_rhombus_length / 2) {
					for (int j = 0; j < rhombus_width; j++) {
						if (j == 0) {//left side
							printf("|");
						}
						else if (j == rhombus_width - 1) {//right side
							printf("|");
						}
						else if (j == line_center) {// line center
							printf("+");
						}
						else {
							printf(" ");
						}
					}
				}
				//bottom side
				if (i > (int)total_rhombus_length / 2) {
					for (int j = 0;j < rhombus_width;j++) {
						//print center
						if (j == line_center) {
							printf("*");
						}
						//left side
						else if (j < line_center) {
							if (j == i - line_center - 1) {// i - line_center - 1 = location of '\'
								printf("\\");
							}
							else
							{
								printf(" ");
							}
						}
						//right side
						else if (j > line_center) {
							if (j == rhombus_width - i + line_center) {// lrhombus_width - i + line_center = location of '/'
								printf("/");
							}
							else if(j < rhombus_width - i + line_center)
							{
								printf(" ");
							}
						}
					}
				}
				printf("\n");//end of line
			}
			break;
		}

		case '2':{				
			char number_base_20;
			int number_base_10 = 0;
			int power = 0;
			int print_result = 1;
			printf("Enter a reversed number in base 20:\n");
			scanf(" %c", &number_base_20);
			while (1) {
				switch (number_base_20) {
				case '0':
				{
					break;
				}
				case '1':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 1 * add;
					break;
				}
				case '2':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 2 * add;
					break;
				}
				case '3':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 3 * add;
					break;
				}
				case '4':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 4 * add;
					break;
				}
				case '5':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 5 * add;
					break;
				}
				case '6':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 6 * add;
					break;
				}
				case '7':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 7 * add;
					break;
				}
				case '8':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 8 * add;
					break;
				}
				case '9':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 9 * add;
					break;
				}
				case 'A':
				case 'a':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 10 * add;
					break;
				}
				case 'B':
				case 'b':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 11 * add;
					break;
				}
				case 'C':
				case 'c':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 12 * add;
					break;
				}
				case 'D':
				case 'd':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 13 * add;
					break;
				}
				case 'E':
				case 'e':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 14 * add;
					break;
				}
				case 'F':
				case 'f':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 15 * add;
					break;
				}
				case 'G':
				case 'g':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 16 * add;
					break;
				}
				case 'H':
				case 'h':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 17 * add;
					break;
				}
				case 'I':
				case 'i':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 18 * add;
					break;
				}
				case 'J':
				case 'j':
				{
					int add = 1;
					int power_by = 20;
					for (int i = 1; i <= power; i++) {
						add = add * 20;
					}
					number_base_10 = number_base_10 + 19 * add;
					break;
				}
				case ' ':
				{
					break;
				}
				case '\n':
				{
					break;
				}
				default: {
					print_result = 0;
					printf("Error! %c is not a valid digit in base 20\n", number_base_20);
					break;
				}
				}
				if (number_base_20 != ' ')
				{
					if (number_base_20 != (int)'\n')
					{
						power++;
					}
				}
				
				scanf("%c", &number_base_20);
				if (number_base_20 == '\n')
				{
					break;
				}
			}
			if (print_result)
			{
				printf("%d\n", number_base_10);
			}
			break;
		}

		case '3':{
			int base;
			char user_number;
			
			while (1) {
				printf("Enter a base (2-10):\n");
				scanf("%d", &base);
				if (base < 2 || base > 10) {
					printf("not a valid base\n");
				}
				else{
					break;
				}
			}
			printf("Enter a reversed number in base %d:\n", base);
			scanf(" %c",&user_number);
			int power = 0;
			int result = 0;
			int error = 0;
			while (1)
			{
				if (user_number == '\n')
				{
					break;
				}
				else if (user_number - '0' >= base) {
					printf("Error! %c is not a valid digit in base %d\n",user_number, base);
					error = 1;
					break;
				}
				{
					int add = user_number - '0';
					for (int i = 1; i <= power;i++) {
						add *= base;
					}
					result = result + add;
					power++;
					scanf("%c", &user_number);
				}
			}
			if (!error) {
				printf("%d\n", result);
			}
			break;
		}

		case '4':{
			int user_input_number ;
			printf("Enter a number:\n");
			scanf("%d", &user_input_number);
			int prev_number = user_input_number - 1;
			if ((user_input_number & prev_number) == 0) {
				printf("%d is a power of 2\n", user_input_number);
			}
			else
			{
				printf("%d is not a power of 2\n", user_input_number);
			}
			break;
		}

		case '5':{
			int user_first_number;
			int user_second_number;
			printf("Enter two numbers:\n");
			scanf("%d %d", &user_first_number, &user_second_number);
			int xor_of_two_inputs = user_first_number ^ user_second_number;
			int num_of_defference = 0;
			while (1) {
				if (xor_of_two_inputs == 1)
				{
					num_of_defference = num_of_defference + 1;
					break;
				}
				else if (xor_of_two_inputs % 2 == 1)
				{
					num_of_defference = num_of_defference + 1;
				}
				xor_of_two_inputs /= 2;
			}
			printf("There are %d different bits\n", num_of_defference);
			break;
		}

		case '6':{
			printf("Enter two numbers:\n");
			int user_first_number;
			int user_second_number;
			scanf("%d %d", &user_first_number, &user_second_number);
			while (user_first_number != 0)
			{
				int carry = user_second_number & user_first_number;
				user_second_number = user_second_number ^ user_first_number;
				user_first_number = carry << 1;
			}
			printf("%d\n", user_second_number);
			break;
		}

		case '7':{
			printf("Enter two numbers:\n");
			int user_first_number;
			int user_second_number;
			scanf("%d %d", &user_first_number, &user_second_number);
			int user_second_number_copy = user_second_number;
			int user_second_number_copy_copy = user_second_number;
			for(int i = 1; i < user_first_number; i++)
			{
				user_second_number_copy = user_second_number_copy_copy;
				while (user_second_number_copy != 0)
				{
					int carry = user_second_number & user_second_number_copy;
					user_second_number = user_second_number ^ user_second_number_copy;
					user_second_number_copy = carry << 1;
				}
			}
			printf("%d\n", user_second_number);
			break;
		}

		default:
			printf("Wrong option!\n");
			break;
		}
		printf("Choose an option:\n1. Rhombus\n2. Base 20 to Decimal\n3. Base to Decimal\n4. Pow2\n5. Different bits\n6. Add\n7. Multiply\n0. Exit\n");
		scanf(" %c", &user_input);
	}

	return 0;
}