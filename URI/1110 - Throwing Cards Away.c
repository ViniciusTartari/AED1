#include <stdio.h>
#define max 100

int w=0;

typedef struct tfila
{
	int vetor[max];
	int inicio;
	int final;
}fila;
void inicializa_fila(fila *f)
{
	f->inicio=0;
	f->final=-1;
}
int fila_cheia(fila *f)
{
	if(f->final - f->inicio == max-1)
		return(1);
	else
		return(0);
}
int fila_vazia(fila *f)
{
	if(f->final < f->inicio)
		return(1);
	else
		return(0);
}
int enfila(fila *f, int num)
{
	if (fila_cheia(f))
		return(0);
	else
	{
		f->final++;
		f->vetor[f->final] = num;
		return(1);
	}
}
int desenfila(fila *f)
{
	if (fila_vazia(f))
		return(0);
	else
	{
		f->inicio++;
		return(1);
	}
}
void monta_fila(fila *f, int n)
{
	int i;
	for (i=0;i<n;i++)
		enfila(f,i+1);
}
int joga_fora(fila *f,int n)
{
	monta_fila(f,n);
	int aux;
	
	//if (w==0)
		printf("Discarded cards: ");
	/*else
		printf("\nDiscarded cards: ");
		*/
	while (f->final - f->inicio >= 2)
	{
		printf("%d, ",f->vetor[f->inicio]);
		desenfila(f);
		aux = f->vetor[f->inicio];
		desenfila(f);
		f->final++;
		f->vetor[f->final] = aux;
		if (f->final - f->inicio < 2)
			printf("%d\n",f->vetor[f->inicio]);
	}
	//w++;
	return(f->vetor[f->final]);
}
int main ()
{
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		fila f;
		inicializa_fila(&f);
		printf("Remaining card: %d\n",joga_fora(&f,n));
	}
	return(0);
}
