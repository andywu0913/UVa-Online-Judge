#include <stdio.h>

void decimal2binary(char[], int);
void skipLeadingZero(char[]);
int countOnes(char[]);

int main()
{
	unsigned int temp;
	while(scanf("%d", &temp) != EOF && temp != 0)
	{
		char binary[33];
		decimal2binary(binary, temp);
		skipLeadingZero(binary);
		printf("The parity of %s is %d (mod 2).\n", binary, countOnes(binary));
	}
	return 0;
}

void decimal2binary(char binary[], int number)
{
	for(int i = 0 ; i < 32 ; i++)
		binary[i] = '0';
	binary[32] = '\0';
	for(int i = 31 ; number != 0 ; i--)
	{
		binary[i] = number % 2 + '0';
		number >>= 1;
	}
}

void skipLeadingZero(char binary[])
{
	int numberOfZeros = 0;
	while(binary[numberOfZeros] == '0')
	{
		numberOfZeros++;
	}
	for(int i = 0 ; numberOfZeros < 33 ; i++, numberOfZeros++)
		binary[i] = binary[numberOfZeros];
}

int countOnes(char binary[])
{
	int count = 0;
	for(int i = 0 ; binary[i] != '\0' ; i++)
		if(binary[i] == '1')
			count++;
	return count;
}