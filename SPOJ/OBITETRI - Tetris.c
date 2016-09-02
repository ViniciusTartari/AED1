#include <stdio.h>
#define TAM 16

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
int main (void)
{	
	int rodadas,i,j;
	int teste=1,maior,menor,aux,aux2,qnt=0;
	while(scanf("%d", &rodadas) && rodadas!=0)
	{
		player players[1000];
		for(i=0;i<rodadas;i++)
		{
			int soma=0;
			scanf("%s", players[i].nome);
			scanf("%d", &aux);
			maior=aux;
			menor=aux;
			soma=aux;
			for(j=0;j<11;j++)
			{
				scanf("%d", &aux);
				if(maior < aux)
					maior = aux;
				if(menor > aux)
					menor = aux;
				soma+=aux;
			}
			soma -= maior;
			soma -= menor;
			players[i].pontos = soma;
		}
		
		printf("Teste %d\n",teste);
		teste++;
		
		insertion_sort(players,rodadas); //ordenacao
		
		aux2=1;
		for(i=rodadas-1;i>=0;i--)
		{
			if (players[i].pontos != players[i+1].pontos) //pra conserta as posicoes
				qnt = aux2;
			printf("%d %d %s\n",qnt,players[i].pontos,players[i].nome);
			aux2++;
		}
		printf("\n");
	}
	return 0;
}

