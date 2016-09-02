#include <stdio.h>

int main () 
{
	int n, i,cont=0;
	while (scanf("%d", &n) && n!=0) 
	{
		for (i = 1; i*i <= n; i++)
		{
			if(cont==0)
			{
				printf("%d", i*i);
				cont++;
			}
			else
				printf(" %d", i*i);
		}
		cont=0;
		printf ("\n");
	}
	return 0;
}
