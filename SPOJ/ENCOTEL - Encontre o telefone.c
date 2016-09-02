#include <stdio.h>
#include <string.h>
#define MAX 31

int main ()
{
	char expres [MAX];
	int i;
	while (scanf("%s",expres)>0)
	{
		for (i=0;i<strlen(expres);i++)
		{
			if ((expres[i] == 'A') || (expres[i] == 'B') || (expres[i] == 'C'))
				printf("2");
			else if ((expres[i] == 'D') || (expres[i] == 'E') || (expres[i] == 'F'))
				printf("3");
			else if ((expres[i] == 'G') || (expres[i] == 'H') || (expres[i] == 'I'))
				printf("4");
			else if ((expres[i] == 'J') || (expres[i] == 'K') || (expres[i] == 'L'))
				printf("5");
			else if ((expres[i] == 'M') || (expres[i] == 'N') || (expres[i] == 'O'))
				printf("6");
			else if ((expres[i] == 'P') || (expres[i] == 'Q') || (expres[i] == 'R') || (expres[i] == 'S'))
				printf("7");
			else if ((expres[i] == 'T') || (expres[i] == 'U') || (expres[i] == 'V'))
				printf("8");
			else if ((expres[i] == 'W') || (expres[i] == 'X') || (expres[i] == 'Y') || (expres[i] == 'Z'))
				printf("9");
			else
				printf("%c",expres[i]);
		}
		printf("\n");
	}
	return (0);
}
