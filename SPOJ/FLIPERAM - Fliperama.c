#include <stdio.h>

void selection(int *num, int tam) 
{ 
	int i, j, min, aux;
	
	for (i=0;i<(tam-1);i++) 
	{
		min = i;
		for (j=i+1;j<tam;j++) 
		{
			if(num[j] < num[min])
				min = j;
		}
		if (i!=min) 
		{
			aux = num[i];
			num[i] = num[min];
			num[min] = aux;
		}
	}
}

int main ()
{
	int m,n,i,cont=0;
	scanf("%d %d",&n,&m);
	int vetor[n];
	
	for (i=0;i<n;i++)
		scanf("%d",&vetor[i]);
	
	selection(vetor,n);
	
	for (i=(n-1);cont<m;i--)
	{
		printf("%d\n",vetor[i]);
		cont++;
	}
	return (0);
}
