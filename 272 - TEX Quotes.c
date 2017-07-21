#include<stdio.h>

int main()
{
	int quote = 0;
	char temp;
	while(scanf("%c", &temp) != EOF)
	{
		if(temp == '\"')
		{
			if(quote % 2 == 0)
				printf("``");
			else
				printf("\'\'");
			quote++;
		}
		else
			printf("%c", temp);
	}
	return 0;
}
