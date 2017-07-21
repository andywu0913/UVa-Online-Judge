#include<stdio.h>
#include<string.h>

void swap(char[], char[]);
void fillBlank(char[], int, int, int);

int main()
{
	int number;

	while(scanf("%d", &number) != EOF)
	{
		char fileNames[number][61];
		int longestFileName = 0;
		int rows;
		int columns;

		for(int i = 0 ; i < number ; i++)
		{
			scanf("%s", &fileNames[i]);
			if(strlen(fileNames[i]) > longestFileName)
				longestFileName = strlen(fileNames[i]);
		}

		columns = (60 - longestFileName) / ( longestFileName + 2 ) + 1;
		rows = number / columns + ( number % columns != 0);

		for(int i = 0 ; i < number ; i++)
		{
			int temp = i;
			for(int j = i + 1 ; j < number ; j++)
			{
				if(strcmp(fileNames[temp], fileNames[j]) > 0)
					temp = j;
			}
			swap(fileNames[i], fileNames[temp]);
		}

		printf("------------------------------------------------------------\n");
		for(int i = 0 ; i < rows ; i++)
		{
			for(int j = 0 ; j < columns ; j++)
			{
				int index = rows * j + i;
				if(index < number)
				{
					printf("%s", fileNames[index]);
					fillBlank(fileNames[index], longestFileName, columns, j);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

void swap(char s1[], char s2[])
{
	int length;
	
	if(strlen(s1) > strlen(s2))
		length = strlen(s1);
	else
		length = strlen(s2);
	for(int i = 0 ; i <= length ; i++)
	{
		char temp = s1[i];
		s1[i] = s2[i];
		s2[i] = temp;
	}
}

void fillBlank(char fileName[], int longestFileName, int totalColumns, int currentColumns)
{
	int length = (currentColumns == (totalColumns - 1) ? longestFileName : longestFileName + 2);
	for(int i = strlen(fileName) ; i < length ; i++)
		printf(" ");
}
