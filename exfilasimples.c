#include <stdio.h>
#define max 100

typedef struct titem
{
	int chave;
}item;

typedef struct tfila
{
	item itens[max];
	int inicio;
	int final;
}fila;

void inicializa_fila(fila *f)
{
	f->inicio = -1;
	f->final = 0;
}
int fila_vazia(fila *f)
{
	if (f->inicio == f->final)
		return(1);
	else
		return(0);
}
int fila_cheia(fila *f)
{
	if (f->final - f->inicio == max-1)
		return (1);
	else
		return (0);
}
int enfilera(fila *f,int chave)
{
	if (fila_cheia(f))
		return (0);
	else
	{
		f->final++;
		f->itens[f->final].chave = chave;
		return (1);
	}
}
int desenfilera(fila *f)
{
	if (fila_vazia(f))
		return (0);
	else
	{
		f->inicio++;
		return (1);
	}
}
int desenfilera2(fila *f) //rearranja
{
	int i;
	if (fila_vazia(f))
		return (0);
	else
	{
		for (i = f->inicio;i < f->final;i++)
			f->itens[i] = f->itens[i+1];
		f->final++;
		return (1);
	}
}
int busca_fila(fila *f,int elem)
{
	if (elem == f->inicio || elem == f->final)
		return(1);
	else
		return(0);
}

void main ()
{
	fila f;
	inicializa_fila(&f);
}
