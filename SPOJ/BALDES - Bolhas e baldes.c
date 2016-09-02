#include <stdio.h>
#include <stdlib.h>

void troca (int *vetor, int i, int j) 
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int main () 
{
	int n, i, trocas;
	while (scanf ("%d", &n)>0 && n!=0) 
	{
		int vetor[n];
		for (i = 0; i < n; i++) 
			scanf ("%d", &vetor[i]);
		trocas = 0;
		i = 0;
		while (i < n) 
		{
			while (vetor[i] != i+1) 
			{
				troca (vetor, i, vetor[i]-1);
				trocas = 1-trocas;
			}
			i++;
		}
		if (trocas == 0) 
			printf ("Carlos\n");
		else 
			printf ("Marcelo\n");
	}
	return 0;
}

