#include <stdio.h>

int main ()
{
	int a,b,c,aux;
	scanf("%d %d %d",&a,&b,&c);
	//ordena
	if (b > c)
	{
		aux = b;
		b = c;
		c = aux; 
	}
	if (a > c)
	{
		aux = a;
		a = c;
		c = aux; 
	}
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux; 
	}
	//classificacao
	if (c >= a + b)
		printf("n\n");
	else if ((c*c) < (a*a) + (b*b))
		printf("a\n");
	else if ((c*c) > (a*a) + (b*b))
		printf("o\n");
	else
		printf("r\n");
	return (0);
}
