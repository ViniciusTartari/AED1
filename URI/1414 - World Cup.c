#include <stdio.h> 
int main (void) 
{ 
	int times,participantes,soma=0, i, pontos, empates; 
	char nome[10]; 
	while(scanf("%d %d",&times,&participantes) && times!=0) 
	{ 
		for(i=0;i<times;i++) 
		{ 
			scanf("%s %d", nome, &pontos); 
			soma = soma + pontos; 
		}
		empates = (participantes*3)-soma;
		printf("%d\n",empates);
		soma=0;
	} 
	return 0; 
}
