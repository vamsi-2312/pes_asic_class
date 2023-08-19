#include <stdio.h>

int main()
{
	int i, sum = 0, n = 10;
	for(i = 1; i <= n; ++i)
	{
	sum += i;
	}
	printf("Sum of Numbers from 1 to %d = %d\n", n, sum);
	return 0;
}
