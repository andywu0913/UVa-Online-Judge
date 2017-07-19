#include<stdio.h>

int main()
{
	char temp;
	while(scanf("%c", &temp) != EOF)
	{
		if(temp == '\n')
			printf("\n");
		else
			printf("%c", temp-7);
	}
	return 0;
}