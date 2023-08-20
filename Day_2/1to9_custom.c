#include <stdio.h>

extern int load(int x, int y);

int main()
{
	int result = 0;
	int count = 9;
	result = load(0x0, count+1);//function call
	printf("Sum of numbers from 1 to %d = %d\n", count, result);
	
}
