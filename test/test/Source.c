#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define SIZE 5


int main()
{
	time_t seconds;

	seconds = time(NULL);
	printf("Hours since January 1, 1970 = %ld\n", seconds );
	printf("%d\n%d",sizeof(seconds), seconds);

	return(0);
}

