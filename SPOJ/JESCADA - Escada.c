#include <stdio.h>

int main ()
{
	int n,i,soma=0;
	
	scanf("%d",&n);
	
	int vetor[n];
	
	for (i=0;i<n;i++)
		scanf("%d",&vetor[i]);
	
	for(i=0;i<n-1;i++)
	{
		if (vetor[i+1]-vetor[i] < 10)
			soma += vetor[i+1]-vetor[i];
		else
			soma += 10;
	}
	soma+=10;
	
	printf("%d\n",soma);
	
	return (0);
}

