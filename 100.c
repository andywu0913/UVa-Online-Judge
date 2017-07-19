#include<stdio.h>

int main()
{
	int num1, num2;
	while(scanf("%d %d", &num1, &num2) != EOF)
	{
		unsigned long maxCycle = 0;

		printf("%d %d ", num1, num2);
		if(num1 > num2)
		{
			int temp = num1;
			num1 = num2;
			num2 = temp;
		}
		for(int i = num1 ; i <= num2 ; i++)
		{
			unsigned long tempCycle = 1;
			for(int n = i ; n != 1 ; tempCycle++)
			{
				if(n & 1 == 1)
					n = n * 3 + 1;
				else
					n = n >> 1;
			}
			if(tempCycle > maxCycle)
				maxCycle = tempCycle;
		}
		printf("%ld\n", maxCycle);
	}
	return 0;
}