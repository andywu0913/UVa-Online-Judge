#include <stdio.h>
#include <string.h>

int main()
{
	int num;
	scanf("%d%c", &num);
	for(int i = 0 ; i < num ; i++)
	{
		int count = 0;
		char temp;
		while(scanf("%c", &temp) != EOF && temp != '\n')
		{
			if((temp >= 'a' && temp <= 'z') || temp == ' ')
				switch(temp)
				{
					case ' ':	count += 1; break;
					case 's':	count += 4; break;
					case 't':	count += 1; break;
					case 'u':	count += 2; break;
					case 'v':	count += 3; break;
					case 'w':	count += 1; break;
					case 'x':	count += 2; break;
					case 'y':	count += 3; break;
					case 'z':	count += 4; break;
					default :	count += (temp - 'a' + 1) % 3 == 0 ? 3 : (temp - 'a' + 1) % 3;
				}
		}
		printf("Case #%d: %d\n", i + 1, count);
	}
	return 0;
}