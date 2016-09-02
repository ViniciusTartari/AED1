#include <stdio.h>

int pontuacao(int cartas[]) 
{
	//primeira regra (sequencia)
	if (cartas[1]==cartas[2]-1 &&cartas [2]==cartas[3]-1 && cartas[3]==cartas[4]-1 && cartas[4]==cartas[5]-1)
		return 200+cartas[1];

	//segunda regra ( 4 iguais )
	if (cartas[1]==cartas[4] || cartas[2]==cartas[5]) 
		return 180+cartas[2];

	//terceira regra ( 3 iguais e um par)
	if ((cartas[1]==cartas[3] && cartas[4]==cartas[5]) || (cartas[3]==cartas[5] && cartas[1]==cartas[2])) 
		return 160+cartas[3];

	//quarta regra ( 3 iguais )
	if (cartas[1]==cartas[3] || cartas[2]==cartas[4] || cartas[3]==cartas[5]) 
		return 140+cartas[3];

	//quinta regra ( 2 pares iguais e uma diferente)
	if ((cartas[1]==cartas[2] && cartas[4]==cartas[5])) 
	{
		if (cartas[1]>cartas[4])
			return (3*cartas[1]+2*cartas[4]+20);
		else
			return (3*cartas[4]+2*cartas[1]+20);
	}
	if ((cartas[1]==cartas[2] && cartas[3]==cartas[4])) 
	{
		if (cartas[1]>cartas[3]) 
			return (3*cartas[1]+2*cartas[3]+20);
		else
			return (3*cartas[3]+2*cartas[1]+20);
	}
	if ((cartas[2]==cartas[3] && cartas[4]==cartas[5])) 
	{
		if (cartas[2]>cartas[4])
			return (3*cartas[2]+2*cartas[4]+20);
		else
			return (3*cartas[4]+2*cartas[2]+20);
	}

	//sexta regra (duas iguais e o resto diferente)
	if (cartas[1]==cartas[2] || cartas[2]==cartas[3])
		return cartas[2];
	if (cartas[3]==cartas[4] || cartas[4]==cartas[5])
		return cartas[4];

	//setima regra (td diferente)
	return 0;
}

int main() 
{
	int n, teste, carta, i, j;
	int cartas[6];//vetor cartas
	scanf("%d", &n);
	for (teste=1; teste<=n; teste++) {
		//Ordenacao pelo alg insertion sort
		for (i=1; i<=5; i++)
		{
			scanf("%d", &carta);
			for (j=i-1; j>0 && cartas[j]>carta; j--)
				cartas[j+1]=cartas[j];
			cartas[j+1]=carta;
		}
		printf("Teste %d\n%d\n\n",teste,pontuacao(cartas));
	}
	return 0;
}
