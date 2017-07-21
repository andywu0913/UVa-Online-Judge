/*	  0      1      2
	B G C  B G C  B G C
	BCG : times[0]
	BGC : times[1]

	CBG : times[2]
	CGB : times[3]
	GBC : times[4]
	GCB : times[5]
*/

#include<stdio.h>

int calculate(int[], int[], int[]);

int main()
{
	int bin[3][3];
	
	while(scanf("%d %d %d %d %d %d %d %d %d", &bin[0][0], &bin[0][1], &bin[0][2], &bin[1][0], &bin[1][1], &bin[1][2], &bin[2][0], &bin[2][1], &bin[2][2]) != EOF)
	{
		int times[6];
		int smallestIndex = 0;
		times[0] = calculate(bin[0], bin[2], bin[1]);
		times[1] = calculate(bin[0], bin[1], bin[2]);
		times[2] = calculate(bin[1], bin[2], bin[0]);
		times[3] = calculate(bin[2], bin[1], bin[0]);
		times[4] = calculate(bin[1], bin[0], bin[2]);
		times[5] = calculate(bin[2], bin[0], bin[1]);
		for(int i = 1 ; i < 6 ; i++)
			if(times[i] < times[smallestIndex])
				smallestIndex = i;
		switch(smallestIndex)
		{
			case 0: printf("BCG %d\n", times[smallestIndex]); break;
			case 1: printf("BGC %d\n", times[smallestIndex]); break;
			case 2: printf("CBG %d\n", times[smallestIndex]); break;
			case 3: printf("CGB %d\n", times[smallestIndex]); break;
			case 4: printf("GBC %d\n", times[smallestIndex]); break;
			case 5: printf("GCB %d\n", times[smallestIndex]); break;
		}
	}
	return 0;
}

int calculate(int b[], int g[], int c[])
{
	int times = 0;
	times += g[0] + c[0]; //B
	times += b[1] + c[1]; //G
	times += b[2] + g[2]; //C
	return times;
}
