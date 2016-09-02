#include <stdio.h>

typedef struct pessoa
{
	int num;
	int acao;
}pessoa;

int verifica (int p, int r)
{
	int i,j,pr,ordem;
	pessoa pessoas[p];
	
	//poe tds as pessoas = x
	for (i=0;i<p;i++)
		pessoas[i].num = 'x';
	
	//leitura posicoes
	for(i=0;i<p;i++)
		scanf("%d",&pessoas[i].num);
	
	//leitura pessoasrestantes(pr), ordem do lider e as acoes
	for(j=0;j<r;j++)
	{
		scanf("%d %d",&pr,&ordem);
		for(i=0;i<p;i++)
		{
			if(pessoas[i].num!='x')
			{
				scanf("%d",&pessoas[i].acao);
				if(pessoas[i].acao!=ordem)
					pessoas[i].num = 'x';
			}
		}
	}
	//resultado
	for(i=0;i<p;i++)
		if(pessoas[i].num!='x')
			return(pessoas[i].num);
}

int main ()
{
	int p,r,k=1;
	while(scanf("%d %d",&p,&r)!=EOF && (p!=0 && r!=0))
	{
		printf("Teste %d\n%d\n",k,verifica(p,r));
		k++;
	}
	return(0);
}
