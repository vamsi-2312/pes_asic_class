#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long int max = (unsigned long long int) (pow(2,64)-1);
	unsigned long long int bey_max = (unsigned long long int) (pow(2,99)-1);
	unsigned long long int min = (unsigned long long int) (pow(2,64)*-1);
	unsigned long long int mid = (unsigned long long int) (pow(2,10)-1);
	printf("The highest value of unsigned long long int = %llu\n",max);
	printf("The value of bey_max(if value more than max) = %llu\n",bey_max);
	printf("The lowest value of unsigned long long int = %llu\n",min);
	printf("The value of mid = %llu\n",mid);
	return 0;
}

