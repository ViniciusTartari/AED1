#include <stdio.h>
#include <string.h>
struct tipot
{
	int valortabela;
	int quantidade;
};
void insertion(struct tipot *tabela) 
{
   int i, j, k	;
   struct tipot eleito;
   for (i = 33; i < 128; i++)
   {
      eleito = tabela[i];
      j = i - 1;
      while ((j>=32) && (eleito.quantidade < tabela[j].quantidade)) 
	  {
         tabela[j+1] = tabela[j];
         j--;
      }
      tabela[j+1] = eleito;
      while ((j>=32) && (eleito.quantidade == tabela[j].quantidade)) 
	  {
         tabela[j+1] = tabela[j];
         j--;
      }
      tabela[j+1] = eleito;
	  
   }
}
int main (void)
{
	struct tipot tabela[128];
	int i,quebra=0;
	char caracter[1001];
	for(i=32;i<128;i++)
	{
		tabela[i].quantidade=0;
		tabela[i].valortabela=0;
	}
	i=0;
	while(scanf("%c",&caracter[i])!=EOF)
	{
		if(quebra!=0)
		{
			printf("\n");
		}
		tabela[(int)caracter[i]].quantidade++;
		tabela[(int)caracter[i]].valortabela=(int)caracter[i];
		for(i=1;scanf("%c",&caracter[i])!=EOF&&caracter[i]!='\n';i++)
		{
			
			tabela[(int)caracter[i]].quantidade++;
			tabela[(int)caracter[i]].valortabela=(int)caracter[i];
		}
		insertion(tabela);
		for(i=32;i<128;i++)
		{
			if(tabela[i].quantidade!=0)
			{
				printf("%d %d\n",tabela[i].valortabela, tabela[i].quantidade);
			}
		}
		//printf("\n");
		for(i=0;i<128;i++)
		{
			tabela[i].quantidade=0;
			tabela[i].valortabela=0;
		}
		i=0;
		quebra=1;
	}
	return 0;
}
