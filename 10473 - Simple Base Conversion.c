#include <stdio.h>
#include <ctype.h>
#include <string.h>

int pow(int base, int exp);

int main()
{
	char temp[11];
	while(scanf("%s", temp) != EOF && temp[0] != '-')
	{
		if(temp[1] == 'x')
		{
			int number;
			sscanf(temp, "%x", &number);
			printf("%d\n", number);
		}
		else
		{
			int number;
			sscanf(temp, "%d", &number);
			sprintf(temp, "%x", number);
			int wordLength = strlen(temp);
			for(int i = 0; i < wordLength ; i++)
				temp[i] = toupper(temp[i]);
			printf("0x%s\n", temp);
		}
	}
	return 0;
}
