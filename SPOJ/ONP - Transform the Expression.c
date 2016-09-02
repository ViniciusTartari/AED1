#include <stdio.h>
#define max 100001

typedef struct tpilha
{
	char string[max];
	int topo;
}pilha;

void inicializa_pilha (pilha *p)
{
	p->topo = -1;
}

int pilha_vazia (pilha *p)
{
	if (p->topo == -1)
		return(1);
	else
		return(0);
}

int pilha_cheia (pilha *p)
{
	if (p->topo == max-1)
		return(1);
	else
		return(0);
}

int empilha (pilha *p, char carac)
{
	if (pilha_cheia(p))
		return(0);
	else
	{
		p->topo++;
		p->string[p->topo] = carac;
		return(1);
	}
}

int desempilha (pilha *p)
{
	if (pilha_vazia(p))
		return(0);
	else
	{
		p->topo--;
		return (1);
	}
}

void rpn (char *s)
{
	pilha p;
	inicializa_pilha(&p);
	int i=0;
	
	while(s[i]!='\0')
	{
		if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
			empilha(&p,s[i]);
		 else if (s[i] == ')')
		{
			printf("%c",p.string[p.topo]);  
			desempilha(&p);
		}
		else if (s[i] != '(')
			printf("%c",s[i]);
		i++;
	}
	while(pilha_vazia(&p)!=1)
	{
		printf("%c",p.string[p.topo]);
		desempilha(&p);
	}
}

int main ()
{
	int t,i;
	scanf("%d ",&t);
	char s[max];
	for (i=0;i<t;i++)
	{
		scanf("%s",s);
		rpn(s);
		printf("\n");
	}
	return(0);
}
