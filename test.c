#include<stdio.h>

int main()
{
	unsigned long int n1, n2;
	while(scanf("%ld %ld", &n1, &n2) != EOF)
	{
		printf("%ld\n", (n1-n2)*(n1>n2? 1:-1));
	}
	return 0;
}