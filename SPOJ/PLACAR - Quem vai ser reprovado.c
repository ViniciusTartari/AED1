#include <stdio.h>
#define TAM 21

typedef struct player
{
	int pontos;
	char nome[TAM];
}player;

int insertion_sort (player *players, int cont)
{
    int i, j;
	player aux;
    for(i=1;i<cont;i++)
    {
	    aux=players[i];
	    j=i-1;
		//ordena por pontos
	    while((j>=0)&&(aux.pontos<players[j].pontos))
	    {
		    players[j+1]=players[j];
		    j--;
	    }
	    //ordena por nome
	    while((j>=0) && (aux.pontos == players[j].pontos) && (strcmp(players[j].nome,aux.nome))<0)
	    {
		    players[j+1]=players[j];
		    j--;
	    }
	    players[j+1]=aux;
    }
}
int main ()
{	
	int n,i,j,teste=1;
	while(scanf("%d", &n)>0)
	{
		player players[100];
		for(i=0;i<n;i++)
			scanf("%s %d", players[i].nome,&players[i].pontos);
		
		printf("Instancia %d\n",teste);
		teste++;
		insertion_sort(players,n); //ordenacao
		
		printf("%s\n\n",players[0].nome);
	}
	return 0;
}


