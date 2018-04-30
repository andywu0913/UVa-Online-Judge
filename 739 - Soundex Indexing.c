#include <stdio.h>
#include <string.h>

char getEncode(char letter);
void printRow(char name[], char soundexCode[]);

int main(void)
{
	printf("         NAME                     SOUNDEX CODE\n");

	char name[21];
	while(scanf("%s", name) != EOF)
	{
		char result[] = {getEncode(name[0]), '0', '0', '0', '\0'};
		int nameLength = strlen(name);

		for (int i = 1, resultIndex = 1; i < nameLength && resultIndex < 4; i++)
		{
			if(getEncode(name[i]) == '0' || getEncode(name[i]) == getEncode(name[i - 1]))
				continue;

			result[resultIndex] = getEncode(name[i]);
			resultIndex++;
		}

		result[0] = name[0];
		printRow(name, result);
	}

	printf("                   END OF OUTPUT\n");
	return 0;
}

char getEncode(char letter)
{
	switch(letter)
	{
		case 'B':
		case 'P':
		case 'F':
		case 'V':
			return '1';
		case 'C':
		case 'S':
		case 'K':
		case 'G':
		case 'J':
		case 'Q':
		case 'X':
		case 'Z':
			return '2';
		case 'D':
		case 'T':
			return '3';
		case 'L':
			return '4';
		case 'M':
		case 'N':
			return '5';
		case 'R':
			return '6';
		default:
			return '0';
	}
	return '0';
}

void printRow(char name[], char soundexCode[])
{
	printf("         %s", name);
	for (int i = 10 + strlen(name); i < 35; i++)
		printf(" ");
	printf("%s\n", soundexCode);
}