#include <stdio.h>
#define max 100

typedef struct titem
{
	int chave;
}item;

typedef struct tpilha
{
	item itens[max];
	int topo;
}pilha;

void inicializa_pilha(pilha *p)
{
	p->topo=-1;
}
int pilha_vazia(pilha *p)
{
	if (p->topo == -1)
		return (1);
	else
		return (0);
}
int pilha_cheia(pilha *p)
{
	if (p->topo == max-1)
		return (1);
	else
		return (0);
}
int empilha(pilha *p,int chave)
{
	if (pilha_cheia(p))
		return (0);
	else
	{
		p->topo++;
		p->itens[p->topo].chave = chave;
		return(1);
	}
}
int desempilha(pilha *p)
{
	if (pilha_vazia(p))
		return (0);
	else
	{
		p->topo--;
		return (1);
	}
}
int busca_pilha(pilha *p,int elem)
{
	if(p->topo == elem)
		return(1);
	else
		return(0);
}
int topo (pilha *p)
{
	if (pilha_vazia(p))
		return (0);
	else
		return (p->itens[p->topo].chave);
}

void main ()
{
	pilha p;
	inicializa_pilha(&p);
}