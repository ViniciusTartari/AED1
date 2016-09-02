#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int a,v,x,y,teste=1,i,maior=0;
	while(scanf("%d %d",&a,&v)>0 && (a!=0 && v!=0))
	{
		int vetor[a];
		for(i=1;i<=a;i++)
			vetor[i]=0;
		for(i=0;i<v;i++)
		{
			scanf("%d %d", &x, &y);
			vetor[x]++;
			vetor[y]++;
			if(vetor[x] > maior)
				maior = vetor[x];
			if(vetor[y] > maior)
				maior = vetor[y];
		}
		printf("Teste %d\n",teste);
		for(i = 1;i <= a;i++)
			if(vetor[i] == maior)
				printf("%d ",i);
		printf("\n");
		maior=0;
		teste++;
		printf("\n");
	}
	return 0;
}
